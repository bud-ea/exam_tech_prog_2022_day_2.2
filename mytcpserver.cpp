#include "mytcpserver.h"
#include "message.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    // mainTcpServer->close();
    mainTcpServer->close();
    //server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mainTcpServer = new QTcpServer(this);
    connect(mainTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if (mainTcpServer->listen(QHostAddress::Any, 33333)) {qDebug() << "Server started on port 33333";}
    else {qDebug() << "Server not started, check for errors";}
    
}

void MyTcpServer::slotNewConnection(){
//    if(server_status==1){
    QTcpSocket* newSocket;
    newSocket = mainTcpServer->nextPendingConnection();
    connect(newSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
    connect(newSocket, &QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
    mTcpSocket.push_back(newSocket);
    qDebug() << "Client connected";
//    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket *senderSocket = (QTcpSocket*)sender();
    QString res="";
    while(senderSocket->bytesAvailable()>0)
    {
        QByteArray array = senderSocket->readAll();
        res.append(array);
    }

    Message encryptedMessage(&res);
    encryptedMessage.encryptMessage();
    // QByteArray msg = "123";

    for (auto el : mTcpSocket) {
        el->write(encryptedMessage.getMessage());
    }
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket *senderSocket = (QTcpSocket*)sender();
    senderSocket->close();
}

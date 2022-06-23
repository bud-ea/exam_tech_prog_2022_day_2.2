#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    //server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){

    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
}


void MyTcpServer::slotNewConnection(){
 //   if(server_status==1){
        QTcpSocket * socketDescriptor;
        socketDescriptor = mTcpServer->nextPendingConnection();
        socketDescriptor->write("Hello, World!!! I am echo server!\r\n");
        mTcpSocket.push_back(socketDescriptor);
        connect(socketDescriptor, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(socketDescriptor,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
   // }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket * socketDescriptor = (QTcpSocket*)sender();
    QString text = "";
    while(socketDescriptor->bytesAvailable()>0)
    {
        QByteArray array =socketDescriptor->readAll();
        text.append(array);
    }
    QByteArray array = parser(text);
        tempSocket=mTcpSocket;
        for (int i = 0; i<mTcpSocket.size(); i++){
            tempSocket.front()->write(array);
            tempSocket.pop_front();
        }
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket * socketDescriptor = (QTcpSocket*)sender();
    mTcpSocket.remove(socketDescriptor);
    socketDescriptor->close();
}

#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <parsing.h>

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

    QTcpSocket *socket;
    socket = mTcpServer->nextPendingConnection();
    mTcpSocket.push_back(socket);
    socket->write("Hello, World!!! I am echo server!\r\n");
    connect(socket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
    connect(socket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);

}

void MyTcpServer::slotServerRead(){
    QTcpSocket *socket = (QTcpSocket*)sender();
    if (socket->bytesAvailable()>0) {
        QByteArray command = socket->readAll();
        if (command.length() > 0) {
            //socket->write("successfully\r\n");
            command.remove(command.size()-2,2); //для Putty
            qDebug() << "Client " << socket->socketDescriptor() << " sent message: " << command;
       }
        QByteArray toClients = parsing(command);
        socketList = mTcpSocket;
        for (int i = 0; i<mTcpSocket.size(); i++){
             socketList.front()->write(toClients);
             socketList.pop_front();
        }
        //socket->write(parsing(command));
    }
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket *socket = (QTcpSocket*)sender();
    mTcpSocket.remove(socket);
    socket->close();
    //mTcpSocket->close();
}

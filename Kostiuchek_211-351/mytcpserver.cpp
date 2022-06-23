#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    //server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333))
    {
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection()
{
        QTcpSocket *tempSocket;
        tempSocket = mTcpServer->nextPendingConnection();
        tempSocket->write("Hello, World!!! I am echo server!\r\n");
        mTcpSocket.push_back(tempSocket);
        connect(tempSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(tempSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
}

void MyTcpServer::slotServerRead()
{
    QTcpSocket *tempSock = (QTcpSocket*)sender();
    QString res="";
    while(tempSock->bytesAvailable()>0)
    {
        QByteArray array =tempSock->readAll();
        res.append(array);
    }

    QByteArray array = parsing(res);
    tempSocketList=mTcpSocket;
    for (int i = 0; i<mTcpSocket.size(); i++)
    {
        tempSocketList.front()->write(array);
        tempSocketList.pop_front();
    }
}

void MyTcpServer::slotClientDisconnected()
{
    QTcpSocket *tempSock = (QTcpSocket*)sender();
    mTcpSocket.remove(tempSock);
    tempSock->close();
}

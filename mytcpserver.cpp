#include "mytcpserver.h"
#include "sypher.h"
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
        QTcpSocket *tempSocket;
        tempSocket = mTcpServer->nextPendingConnection();
        mTcpSocket.push_back(tempSocket);
        tempSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(tempSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(tempSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
   // }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket* tempSock=(QTcpSocket*)sender();
    QString res="";
    QByteArray arr;

    while(tempSock->bytesAvailable()>0)
    {
        QByteArray array =tempSock->readAll();
        //res=tempSock->readAll();
        res.append(array);
        //res+=array;
        //arr.append(array);
        //mTcpSocket->write(array);
    }
    QString h=task(res);
    QByteArray g=h.toUtf8();
    //QByteArray array=task(res);
    //re.append(task(res));
    //QString d=task(res);
    //qDebug()<<d;
    //tempSock->write(re);
    //qDebug()<<arr;
    qDebug()<<h;
    for (auto it=mTcpSocket.begin();it!=mTcpSocket.end();it++)
    {
        tempSock=*it;
        tempSock->write(g);
    }
    //tempSock->write(g);
    //tempSock->write(arr);
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* tempSock=(QTcpSocket*)sender();
    mTcpSocket.remove(tempSock);
    tempSock->close();
}


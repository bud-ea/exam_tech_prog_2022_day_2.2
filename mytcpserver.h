
#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include "mytcpthread.h"
#include <QObject>
#include <QTcpServer>
#include <QtNetwork>
#include <QDebug>
#include <QTcpSocket>


class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:

    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
protected:

    void incomingConnection(qintptr socketDescriptor);
private:
};

#endif

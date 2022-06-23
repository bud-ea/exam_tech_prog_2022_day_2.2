#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "functionsforserver.h"
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <list>
#include <QStringList>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();

    void slotServerRead();
private:
    QTcpServer * mTcpServer;
    std::list<QTcpSocket*> mTcpSocket;
    std::list<QTcpSocket*> tempSocketList;
};
#endif // MYTCPSERVER_H

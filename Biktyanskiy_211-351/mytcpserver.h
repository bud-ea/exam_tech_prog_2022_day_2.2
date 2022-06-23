#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include "functionsforserver.h"

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QStringList>
#include <list>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
protected:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();
private:
    QTcpServer * mTcpServer;
    std::list<QTcpSocket *> mTcpSocket;
    std::list<QTcpSocket *> tempSocket;
    //int server_status;
};
#endif // MYTCPSERVER_H








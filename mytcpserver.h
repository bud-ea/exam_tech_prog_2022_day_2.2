#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QList>
#include <QThread>

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
    // void sendToAll();
    // void incomingConnection(qintptr socketDescriptor);
private:
    QTcpServer * mainTcpServer;
    QList<QTcpSocket*> mTcpSocket;
    //int server_status;
};
#endif // MYTCPSERVER_H








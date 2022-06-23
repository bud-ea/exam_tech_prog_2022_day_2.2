
#ifndef MYTCPTHREAD_H
#define MYTCPTHREAD_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>


class MyTcpThread : public QThread
{
        Q_OBJECT
public:

    explicit MyTcpThread(qintptr threadDesc, QObject *parent = nullptr);
    ~MyTcpThread();
    public slots:

        void readyRead();
        void disconnected();

protected:

       void run();
private:
       QTcpSocket *socket;
       qintptr socketDescriptor;
};

#endif


#include "singleton.cpp"
#include "mytcpthread.h"

MyTcpThread::~MyTcpThread() {
    requestInterruption();
    wait();
}

MyTcpThread::MyTcpThread(qintptr threadDesc, QObject *parent) : QThread{parent} {
    this->socketDescriptor = threadDesc;
}

void MyTcpThread::run() {
    socket = new QTcpSocket();
    socket->setSocketDescriptor(this->socketDescriptor);
    Singleton* p1 = Singleton::getInstance();
    p1->addSocket(socket);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    exec();
}

QString parse(QString command) {
    QStringList wordList;
    QString word;
    QStringList endWordList;
    for (int i = 0; i<command.length(); i++) {
        int nSimvol = command[i].unicode();
        int flag = 0;
        if ( ((nSimvol >= 97) & (nSimvol <= 122))||((nSimvol >= 65) & (nSimvol <= 90))) {
            flag = 1;
            word.append(command[i]);
        }
        else {
            if (flag == 1)
                wordList.push_front(word);
            flag = 0;
        }
    }
    for (int i = 1; i<=wordList.size(); i++) {
        word = wordList.front();
        for (int j = 0; j<wordList.front().size(); j++) {
            word[i].unicode() = word[i].unicode() + i;
        }
        endWordList.push_front(word);
        wordList.pop_front();
    }
    QString res;
    if (!endWordList.empty()) {
        for(int i = 0; i<=endWordList.size(); i++){
            res+=endWordList.at(i);
        }
    }
    return res;
}


void MyTcpThread::readyRead() {
    if (socket->bytesAvailable()>0) {
        QByteArray array = socket->readAll();
        Singleton* p1 = Singleton::getInstance();
        p1->sendSockets(parse(array.data()));
    }
}

void MyTcpThread::disconnected() {
    socket->deleteLater();
    exit(0);
}

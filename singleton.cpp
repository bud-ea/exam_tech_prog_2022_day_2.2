#include <iostream>
#include <QTcpSocket>

using namespace std;

class Singleton {
public:
   static Singleton* getInstance();

   void addSocket(QTcpSocket* socket)           {
       allSockets.push_back(socket);
   }
   void sendSockets(QString msg) {
           QListIterator<QTcpSocket *> socket(allSockets);
           while (socket.hasNext())
                socket.next() -> write(msg.toLocal8Bit().data());
   }

protected:
   QList <QTcpSocket *> allSockets;

private:
   static Singleton* inst_;
   Singleton() : allSockets() {}
   Singleton(const Singleton&);
   Singleton& operator=(const Singleton&);
};

Singleton* Singleton::inst_ = NULL;

Singleton* Singleton::getInstance() {
   if (inst_ == NULL) {
      inst_ = new Singleton();
   }
   return(inst_);
}

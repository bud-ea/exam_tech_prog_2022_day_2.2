#include "functionsforserver.h"

QByteArray parser(QString enteredText){
        QByteArray text;
        QStringList inputText = enteredText.split('/');
        QString command = inputText.front();
        inputText.pop_front();
        qDebug() << command;
        if (command=="encryption"){
            return encrypt(inputText.at(0));
        }
        else return "error";
}

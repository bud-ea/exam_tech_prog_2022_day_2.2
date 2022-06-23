#include "message.h"
#include "QVector"


Message::Message(QString *message) {
    QByteArray x = "";
    x.append(*message);
    this->message = x;
}

Message::~Message() {
    
}

bool Message::isLatin(QByteRef c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void Message::encryptMessage() {

    QByteArray result;

    result.append(message);
    int count = 1;
    result[0]= result[0] + 1;
    for (int i = 1; i < result.size(); i++) {
        if (isLatin(result[i])) result[i] = result[i] + count;
        else if (isLatin(result[i-1])) {
            count++;
            // if (!isLatin(result[i-1])) count++;
            // result[i] = (result[i-1] != ' ') ? ' ' : '\0';
            // result[i] = ' ';
        }
    }
    this->message = result;

}

QByteArray Message::getMessage() {
    return this->message;
}
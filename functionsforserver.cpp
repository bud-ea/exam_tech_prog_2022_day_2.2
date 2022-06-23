#include "functionsforserver.h"

QByteArray parsing(QString s)
{
    QStringList l = s.split(' ');
    QString i = l.front();
    l.pop_front();
    qDebug() << i;
    return encryption(s);
}

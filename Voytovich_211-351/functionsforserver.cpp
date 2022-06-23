#include "functionsforserver.h"


QByteArray parsing(QString s)
{
    QStringList t = s.split(' ');
    QString i = t.front();
    t.pop_front();
    qDebug() << i;
    return cesar(s);
}

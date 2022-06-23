#include "encryption.h"
QByteArray encrypt(QString data){
    QByteArray res;
    QString word;
    QStringList wordS;
    for (int i = 0; i<data.length(); i++){
        if ((data[i].unicode()>=65 && data[i].unicode()<=90)||
                (data[i].unicode()>=97 && data[i].unicode()<=122)){
            word.append(data[i]);
            qDebug() << data[i];
        } else if(!word.isEmpty()){
            wordS.append(word);
            word.clear();
        }
    }
    for (int j=0; j<wordS.length(); j++){
        QString tempWord=wordS[j];
        for (int l = 0; l<wordS[j].length(); l++){
            tempWord[l]= char(tempWord[l].unicode()+j);
            res.append(tempWord[l].toLatin1());
           // res[l]=res[l]+j;
        }
        res.append(" ");

    }
    qDebug()<<res;

    return res;

}



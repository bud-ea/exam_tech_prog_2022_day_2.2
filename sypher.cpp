#include "sypher.h"
#include <QStringList>
sypher::sypher()
{

}
QString task(QString res)
{
    QString word="";
    for (int i=0;i<res.length();i++)
    {
        if ((res.at(i)>=65)&&(res.at(i)<=90))
        {
            word.append(res.at(i));
        }
        else if ((res.at(i)>=97)&&(res.at(i)<=122))
        {
            word.append(res.at(i));
        }
        else word.append(" ");
    }
    QStringList list;
    QString result;

    list=word.split(" ");
    int k=0;
    /*for (int i=0;i<list.length();i++)
    {
        k+=1;
        QString jj="";
        for (int h=0;h<list.at(i).length();h++)
        {
            //qDebug()<<list.at(i).at(h).digitValue()+k;
            //jj=QString(list.at(i).at(h));
            int y=list.at(i).at(h).digitValue();
            jj=QChar(y+k);
            //jj=QString(list.at(i).at(h).digitValue()+k);
            //result.append(list.at(i).at(h)+k);
            result.append(jj);
        }
    }*/
    return word;
}

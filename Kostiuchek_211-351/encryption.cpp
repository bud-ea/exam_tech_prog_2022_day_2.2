#include "encryption.h"

QByteArray encryption(QString s)
{
    QByteArray res;
    res.append(s);

    int j=1;
    res[0]=res[0]+1;
    for (int i=1; i<res.size(); i++)
    {
        if ((res[i]>='A' && res[i]<='Z') || (res[i]>='a' && res[i]<='z'))
        {
            res[i]=res[i]+j;
        }
        else
        {
            if ((res[i-1]>='A' && res[i-1]<='Z') || (res[i-1]>='a' && res[i-1]<='z'))
            {
                j++;
            }
        }
    }


    return res;

}

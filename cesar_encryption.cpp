#include "cesar_encryption.h"

QByteArray cesar(QString s)
{
    QByteArray result;
    result.append(s);

    int j=1;
    result[0]=result[0]+1;
    for (int i=1; i<result.size(); i++)
    {
        if ((result[i]>='A' && result[i]<='Z')||(result[i]>='a' && result[i]<='z'))
        {
            result[i]=result[i]+j;
        }
        else
        {
            if ((result[i-1]>='A' && result[i-1]<='Z')||(result[i-1]>='a' && result[i-1]<='z'))
            {
                j++;
            }
        }
    }
    return result;
}


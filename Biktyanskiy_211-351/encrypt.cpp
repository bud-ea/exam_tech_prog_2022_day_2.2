#include "encrypt.h"

QByteArray encrypt(QString temp) {
    QByteArray res;
    res.append(temp);
    int cyphCode=1;
    res[0]=res[0]+1;
    for (int i=1; i<res.size(); i++){
        if ((res[i]>='A' && res[i]<='Z') || (res[i]>='a' && res[i]<='z')){
            res[i]=res[i]+cyphCode;
        }
        else{
            if ((res[i-1]>='A' && res[i-1]<='Z') || (res[i-1]>='a' && res[i-1]<='z')){
                cyphCode++;
            }
        }
    }
    return res;
}

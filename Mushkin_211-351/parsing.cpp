#include "parsing.h"

QByteArray parsing(QString command) {
    QStringList wordList;
    QString word;
    QStringList endWordList;
    int flag = 0;
    command.append(" ");
    for (int i = 0; i<command.length(); i++) {
        int nSimvol = command[i].unicode();
        if ( ((nSimvol >= 97) & (nSimvol <= 122))||((nSimvol >= 65) & (nSimvol <= 90))) {
            flag = 1;
            word.append(command[i]);
        }
        else {
            if (flag == 1) {
                wordList.push_back(word);
            word = "";
            }
            flag = 0;
        }
    }
    int size = wordList.size();
    for (int i = 0; i<size; i++) {
        word = wordList.front();
        for (int j = 0; j<word.size(); j++) {
            word[j].unicode() = word[j].unicode() + i + 1;
        }
        endWordList.push_front(word);
        wordList.pop_front();
    }

    QString res;
    if (!endWordList.empty()) {
        res += endWordList.front();
        endWordList.pop_front();
        int size1 = endWordList.size();
        for (int i = 1; i<=size1; i++) {
            res += " ";
            res += endWordList.front();
            endWordList.pop_front();
    }
    }
    QByteArray result;
    result += res.toLocal8Bit();
    return result;
}

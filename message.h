#include <QByteArray>
#include <QObject>

class Message : public QObject
{
    Q_OBJECT

public:
    explicit Message(QString *message);
    ~Message();
    void encryptMessage();
    bool isLatin(QByteRef c);
    QByteArray getMessage();
private:
    QByteArray message;
};
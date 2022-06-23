#include <QtTest>
#include "../encryption.h"


class testFuncforserver : public QObject
{
    Q_OBJECT

public:
    testFuncforserver();
    ~testFuncforserver();

private slots:
    void test_case_1();

};

testFuncforserver::testFuncforserver()
{
}

testFuncforserver::~testFuncforserver()
{

}

void testFuncforserver::test_case_1()
{
    QCOMPARE("a", encrypt("a"));
    QCOMPARE("a", encrypt("aы"));
    QCOMPARE("a b", encrypt("aыb"));
       QCOMPARE("", encrypt(""));
       QCOMPARE("", encrypt("ююьюьюь"));
          QCOMPARE("a b c", encrypt("aыaыa"));
          QCOMPARE("a c e", encrypt("a b c"));
          QCOMPARE("qwerty", encrypt("qwerty"));
}



QTEST_APPLESS_MAIN(testFuncforserver)

#include "tst_testfuncforserver.moc"

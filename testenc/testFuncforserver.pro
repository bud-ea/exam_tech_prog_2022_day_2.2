QT += testlib sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testfuncforserver.cpp \
   ../encryption.cpp


HEADERS += \
   ../encryption.h


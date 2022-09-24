QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testschedule.cpp
SOURCES +=  ../Schedule/qml_schedule.cpp
SOURCES +=  ../Schedule/note.cpp

HEADERS += ../Schedule/qml_schedule.h
HEADERS += ../Schedule/note.h

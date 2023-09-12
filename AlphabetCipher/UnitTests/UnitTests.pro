include(gtest_dependency.pri)

SOURCEPATH = ../FizzBuzzApp
include(../FizzBuzz.pri)

QT += core gui
QT += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TEMPLATE = app
CONFIG += console
CONFIG += thread

SOURCES += \
        main.cpp \
        tst_sampleunittest.cpp

INCLUDEPATH += $${SOURCEPATH}/

TARGET = UnitTests

unix:QMAKE_POST_LINK=./$$TARGET
win32:QMAKE_POST_LINK=./debug/$${TARGET}.exe

include(gtest_dependency.pri)

SOURCEPATH = ../FizzBuzzApp
include(../FizzBuzz.pri)

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TEMPLATE = app
CONFIG += console
CONFIG += thread

SOURCES += \
    main.cpp \
    tst_FizzBuzz.cpp \
    tst_FizzBuzzApp.cpp

INCLUDEPATH += $${SOURCEPATH}/

TARGET = UnitTests

unix:QMAKE_POST_LINK=./$$TARGET
win32:QMAKE_POST_LINK=$${TARGET}.exe

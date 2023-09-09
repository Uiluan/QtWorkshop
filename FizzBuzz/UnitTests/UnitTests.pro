include(gtest_dependency.pri)

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

INCLUDEPATH += \
    ../FizzBuzzApp/

SOURCES += \
    ../FizzBuzzApp/FizzBuzz/FizzBuzz.cpp \
    ../FizzBuzzApp/FizzBuzzApp/FizzBuzzApp.cpp \
    ../FizzBuzzApp/MainWindow/MainWindow.cpp

HEADERS += \
    ../FizzBuzzApp/FizzBuzz/FizzBuzz.h \
    ../FizzBuzzApp/FizzBuzzApp/FizzBuzzApp.h \
    ../FizzBuzzApp/MainWindow/MainWindow.h

FORMS += \
    ../FizzBuzzApp/MainWindow/MainWindow.ui

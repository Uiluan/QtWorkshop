#ifndef MAINWINDOWMOCK_H
#define MAINWINDOWMOCK_H

#include "MainWindow/MainWindowInterface.h"
#include <gmock/gmock.h>

class MainWindowMock : public MainWindowInterface
{
    Q_OBJECT
public:
    MainWindowMock();

    MOCK_METHOD(void, SetOutputString, (const QString&));

    void EmitEncryptButtonClicked(const QString keyword, const QString message);
    void EmitDecryptButtonClicked(const QString keyword, const QString message);
};

#endif // MAINWINDOWMOCK_H

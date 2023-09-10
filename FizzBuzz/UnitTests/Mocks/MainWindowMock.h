#ifndef MAINWINDOWMOCK_H
#define MAINWINDOWMOCK_H

#include "MainWindow/MainWindowInterface.h"
#include <QObject>
#include <QStringList>
#include <gmock/gmock.h>

class MainWindowMock : public MainWindowInterface
{
    Q_OBJECT
public:
    explicit MainWindowMock();

    MOCK_METHOD(void, SetOutputList, (QStringList&));

    void EmitCalculateButtonClicked(const int count);
};

#endif // MAINWINDOWMOCK_H

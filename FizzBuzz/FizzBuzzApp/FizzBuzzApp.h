#ifndef FIZZBUZZAPP_H
#define FIZZBUZZAPP_H

#include "MainWindow/MainWindow.h"

class FizzBuzzApp : public QObject
{
    Q_OBJECT

public:
    FizzBuzzApp(MainWindow& window, QObject *parent = nullptr);
    void Run();

private slots:
    void OnCalculateButtonClicked(const int count);

private:
    MainWindow *Window;
};

#endif // FIZZBUZZAPP_H

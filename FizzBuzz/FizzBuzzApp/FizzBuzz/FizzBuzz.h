#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include "MainWindow/MainWindowInterface.h"
#include <QString>

class FizzBuzz : public QObject
{
    Q_OBJECT
public:
    FizzBuzz(MainWindowInterface& window);
    void Run();

private slots:
    void OnCalculateButtonClicked(const int count);

private:
    MainWindowInterface *Window;
    static void AddFizzToStringIfNeeded(const int number, QString &numberString);
    static void AddBuzzToStringIfNeeded(const int number, QString &numberString);
    static void SetStringToNumberIfNotSetYet(const int number, QString &numberString);
};

#endif // FIZZBUZZ_H

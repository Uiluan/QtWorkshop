#include "FizzBuzz.h"
#include <QStringList>
#include <iostream>

namespace
{
constexpr int FIZZ_FACTOR = 3;
constexpr int BUZZ_FACTOR = 5;
}

FizzBuzz::FizzBuzz(MainWindowInterface& window)
    : Window(&window)
{
    QObject::connect(Window, &MainWindowInterface::CalculateButtonClicked, this, &FizzBuzz::OnCalculateButtonClicked);
}

void FizzBuzz::Run()
{
    Window->show();
}

void FizzBuzz::OnCalculateButtonClicked(const int count)
{
    QStringList list;

    for (int number = 1; number <= count; number++)
    {
        QString numberString;

        AddFizzToStringIfNeeded(number, numberString);
        AddBuzzToStringIfNeeded(number, numberString);
        SetStringToNumberIfNotSetYet(number, numberString);

        list.append(numberString);
    }

    Window->SetOutputList(list);
}

void FizzBuzz::AddFizzToStringIfNeeded(const int number, QString &numberString)
{
    if (number % FIZZ_FACTOR == 0)
    {
        numberString.append("Fizz");
    }
}

void FizzBuzz::AddBuzzToStringIfNeeded(const int number, QString &numberString)
{
    if (number % BUZZ_FACTOR == 0)
    {
        numberString.append("Buzz");
    }
}

void FizzBuzz::SetStringToNumberIfNotSetYet(const int number, QString &numberString)
{
    if (numberString.isEmpty())
    {
        numberString.append(QString::number(number));
    }
}

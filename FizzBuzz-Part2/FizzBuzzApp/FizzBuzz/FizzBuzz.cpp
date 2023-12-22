#include "FizzBuzz.h"
#include <QStringList>
#include <iostream>

FizzBuzz::FizzBuzz(MainWindowInterface& window)
    : Window(&window)
{
    QObject::connect(Window, &MainWindowInterface::CalculateButtonClicked, this, &FizzBuzz::OnCalculateButtonClicked);
}

void FizzBuzz::Run()
{
    Window->show();
}

void FizzBuzz::OnCalculateButtonClicked(const int count, const int fizzValue, const int buzzValue)
{
    QStringList list;

    for (int number = 1; number <= count; number++)
    {
        QString numberString;

        AddFizzToStringIfNeeded(number, fizzValue, numberString);
        AddBuzzToStringIfNeeded(number, buzzValue, numberString);
        SetStringToNumberIfNotSetYet(number, numberString);

        list.append(numberString);
    }

    Window->SetOutputList(list);
}

void FizzBuzz::AddFizzToStringIfNeeded(const int number, const int fizzValue, QString &numberString)
{
    if (number % fizzValue == 0)
    {
        numberString.append("Fizz");
    }
}

void FizzBuzz::AddBuzzToStringIfNeeded(const int number, const int buzzValue, QString &numberString)
{
    if (number % buzzValue == 0)
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

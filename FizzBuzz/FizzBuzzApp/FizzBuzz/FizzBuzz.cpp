#include "FizzBuzz.h"
#include <QStringList>
#include <iostream>

FizzBuzz::FizzBuzz()
{

}

QStringList FizzBuzz::DetermineOutputList(const int count)
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

    return list;
}

void FizzBuzz::AddFizzToStringIfNeeded(const int number, QString &numberString)
{
    if (number % 3 == 0)
    {
        numberString.append("Fizz");
    }
}

void FizzBuzz::AddBuzzToStringIfNeeded(const int number, QString &numberString)
{
    if (number % 5 == 0)
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

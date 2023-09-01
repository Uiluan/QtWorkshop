#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include <QString>

class FizzBuzz
{
public:
    FizzBuzz();
    QStringList DetermineOutputList(const int count);

private:
    static void AddFizzToStringIfNeeded(const int number, QString &numberString);
    static void AddBuzzToStringIfNeeded(const int number, QString &numberString);
    static void SetStringToNumberIfNotSetYet(const int number, QString &numberString);
};

#endif // FIZZBUZZ_H

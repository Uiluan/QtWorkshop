
#include "FizzBuzz/FizzBuzz.h"
#include <QStringList>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(FizzBuzzTests, GivenCountOneWhenDetermineOutputListCalledThenExpectedString)
{
    int testCount = 1;
    FizzBuzz testObject;
    QList<QString> expectedResult({"1"});

    QStringList actualResult = testObject.DetermineOutputList(testCount);

    for(int i = 0; i < testCount; i++)
    {
        EXPECT_STREQ(actualResult.at(i).toUtf8().constData(), expectedResult.at(i).toUtf8().constData());
    }
}

TEST(FizzBuzzTests, GivenCount5WhenDetermineOutputListCalledThenExpectedString)
{
    int testCount = 5;
    FizzBuzz testObject;
    QList<QString> expectedResult({"1", "2", "Fizz", "4", "Buzz"});

    QStringList actualResult = testObject.DetermineOutputList(testCount);

    for(int i = 0; i < testCount; i++)
    {
        EXPECT_STREQ(actualResult.at(i).toUtf8().constData(), expectedResult.at(i).toUtf8().constData());
    }
}

TEST(FizzBuzzTests, GivenCount15WhenDetermineOutputListCalledThenExpectedString)
{
    int testCount = 15;
    FizzBuzz testObject;
    QList<QString> expectedResult({"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"});

    QStringList actualResult = testObject.DetermineOutputList(testCount);

    for(int i = 0; i < testCount; i++)
    {
        EXPECT_STREQ(actualResult.at(i).toUtf8().constData(), expectedResult.at(i).toUtf8().constData());
    }
}



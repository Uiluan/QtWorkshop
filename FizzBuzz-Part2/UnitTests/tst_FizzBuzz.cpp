
#include "FizzBuzz/FizzBuzz.h"
#include "Mocks/MainWindowMock.h"
#include <QListView>
#include <QStringList>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(FizzBuzzTests, WhenRunCalledThenWindowIsShown)
{
    NiceMock<MainWindowMock> windowMock;
    FizzBuzz testApp(windowMock);

    testApp.Run();

    EXPECT_TRUE(windowMock.isVisible());
}

TEST(FizzBuzzTests, GivenCountOneWhenCalculateButtonClickedThenWindowListIsSetWithExpectedList)
{
    NiceMock<MainWindowMock> windowMock;
    FizzBuzz testApp(windowMock);
    QStringList expectedResult({"1"});

    EXPECT_CALL(windowMock, SetOutputList(expectedResult));

    windowMock.EmitCalculateButtonClicked(1, 3, 5);
}

TEST(FizzBuzzTests, GivenCountFiveWhenCalculateButtonClickedThenWindowListIsSetWithExpectedList)
{
    NiceMock<MainWindowMock> windowMock;
    FizzBuzz testApp(windowMock);
    QStringList expectedResult({"1", "2", "Fizz", "4", "Buzz"});

    EXPECT_CALL(windowMock, SetOutputList(expectedResult));

    windowMock.EmitCalculateButtonClicked(5, 3, 5);
}

TEST(FizzBuzzTests, GivenCountFifteenWhenCalculateButtonClickedThenWindowListIsSetWithExpectedList)
{
    NiceMock<MainWindowMock> windowMock;
    FizzBuzz testApp(windowMock);
    QStringList expectedResult({"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"});

    EXPECT_CALL(windowMock, SetOutputList(expectedResult));

    windowMock.EmitCalculateButtonClicked(15, 3, 5);
}



#include "MainWindow/MainWindow.h"
#include <QListView>
#include <QPushButton>
#include <QSpinBox>
#include <QStringList>
#include <QtTest/QSignalSpy>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(MainWindowTests, WhenSetOutputListCalledThenOutputListHasExpectedNumberOfItems)
{
    QStringList expectedList({"1", "2", "Fizz"});
    MainWindow testWindow;
    auto listView = testWindow.findChild<QListView*>("OutputList");
    ASSERT_THAT(listView, NotNull());

    testWindow.SetOutputList(expectedList);

    EXPECT_EQ(listView->model()->rowCount(), 3);
}

TEST(MainWindowTests, WhenSetOutputListCalledThenOutputListHasExpectedText)
{
    QStringList expectedList({"Something", "To", "Put", "In", "List"});
    MainWindow testWindow;
    auto listView = testWindow.findChild<QListView*>("OutputList");
    ASSERT_THAT(listView, NotNull());

    testWindow.SetOutputList(expectedList);

    for(int i = 0; i < listView->model()->rowCount(); i++)
    {
        EXPECT_STREQ(listView->model()->index(i, 0).data().toString().toUtf8().constData(), expectedList.at(i).toUtf8().constData());
    }
}

TEST(MainWindowTests, Given13WhenCalculateButtonClickedThenCalculateButtonClickedSignalIsEmittedWith13)
{
    MainWindow testWindow;
    auto calculateButton = testWindow.findChild<QPushButton*>("CalculateButton");
    ASSERT_THAT(calculateButton, NotNull());
    auto inputField = testWindow.findChild<QSpinBox*>("CountEntryBox");
    ASSERT_THAT(inputField, NotNull());
    QSignalSpy calculateButtonSpy(&testWindow, SIGNAL(CalculateButtonClicked(const int, const int, const int)));

    inputField->setValue(13);
    calculateButton->click();

    ASSERT_EQ(calculateButtonSpy.count(), 1);
    EXPECT_EQ(calculateButtonSpy.takeFirst().at(0), 13);
}

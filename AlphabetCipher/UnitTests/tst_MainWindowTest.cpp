#include "MainWindow/MainWindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSignalSpy>
#include <QString>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(MainWindowTest, GivenTestTextWhenSetOutputStringOutputMessageLabelHasGivenText)
{
    QString expectedString = "Test Text";
    MainWindow testWindow;
    auto outputLabel = testWindow.findChild<QLabel*>("OutputMessageLabel");
    ASSERT_THAT(outputLabel, NotNull());

    testWindow.SetOutputString(expectedString);

    EXPECT_STREQ(outputLabel->text().toUtf8().constData(), expectedString.toUtf8().constData());
}

TEST(MainWindowTest, GivenKeyAndInputTextWhenEncryptButtonClickedThenEncryptButtonClickedIsEmittedWithGivenData)
{
    MainWindow testWindow;
    QString testKey = "Test Key";
    QString testMessage = "Test Message String";

    auto keywordInput = testWindow.findChild<QLineEdit*>("KeywordEditor");
    ASSERT_THAT(keywordInput, NotNull());
    keywordInput->setText(testKey);

    auto inputMessage = testWindow.findChild<QLineEdit*>("InputMessageEditor");
    ASSERT_THAT(inputMessage, NotNull());
    inputMessage->setText(testMessage);

    QSignalSpy encryptSignalSpy(&testWindow, &MainWindow::EncryptButtonClicked);

    auto encryptButton = testWindow.findChild<QPushButton*>("EncryptButton");
    ASSERT_THAT(encryptButton, NotNull());
    encryptButton->click();

    EXPECT_EQ(encryptSignalSpy.count(), 1);
    EXPECT_EQ(encryptSignalSpy.at(0).at(0).value<QString>(), testKey);
    EXPECT_EQ(encryptSignalSpy.at(0).at(1).value<QString>(), testMessage);
}

TEST(MainWindowTest, GivenKeyAndInputTextWhenDecryptButtonClickedThenDecryptButtonClickedIsEmittedWithGivenData)
{
    MainWindow testWindow;
    QString testKey = "Different Test Key";
    QString testMessage = "Some text to decrypt";

    auto keywordInput = testWindow.findChild<QLineEdit*>("KeywordEditor");
    ASSERT_THAT(keywordInput, NotNull());
    keywordInput->setText(testKey);

    auto inputMessage = testWindow.findChild<QLineEdit*>("InputMessageEditor");
    ASSERT_THAT(inputMessage, NotNull());
    inputMessage->setText(testMessage);

    QSignalSpy decryptSignalSpy(&testWindow, &MainWindow::DecryptButtonClicked);

    auto decryptButton = testWindow.findChild<QPushButton*>("DecryptButton");
    ASSERT_THAT(decryptButton, NotNull());
    decryptButton->click();

    EXPECT_EQ(decryptSignalSpy.count(), 1);
    EXPECT_EQ(decryptSignalSpy.at(0).at(0).value<QString>(), testKey);
    EXPECT_EQ(decryptSignalSpy.at(0).at(1).value<QString>(), testMessage);
}


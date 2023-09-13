
#include "AlphabetCipher/AlphabetCipher.h"
#include "Mocks/MainWindowMock.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

class AlphabetCipherTest: public Test
{
public:
    AlphabetCipherTest()
        : WindowMock()
        , TestApp(WindowMock)
    {

    }

    NiceMock<MainWindowMock> WindowMock;
    AlphabetCipher TestApp;
};

/*
 * TODO
 * Run shows window
 * when encrypt button clicked SetOutputString is called with expected encryption (2x)
 * when decrypt button clicked SetOutputString is called with expected decryption (2x)
 */
TEST_F(AlphabetCipherTest, WhenRunCalledThenWindowIsShown)
{
    TestApp.Run();

    EXPECT_TRUE(WindowMock.isVisible());
}

TEST_F(AlphabetCipherTest, GivenKeyYellowWhenEncryptClickedThenSetOutputStringIsCalledWithEncryptedString)
{
    QString expectedEncryption = "crncmlrxstg";
    QString keyword = "yellow";
    QString message = "encryptthis";

    EXPECT_CALL(WindowMock, SetOutputString(expectedEncryption));

    WindowMock.EmitEncryptButtonClicked(keyword, message);
}

TEST_F(AlphabetCipherTest, GivenKeyBlueWhenEncryptClickedThenSetOutputStringIsCalledWithEncryptedString)
{
    QString expectedEncryption = "ipfppqlmfyx";
    QString keyword = "blue";
    QString message = "hellofriend";

    EXPECT_CALL(WindowMock, SetOutputString(expectedEncryption));

    WindowMock.EmitEncryptButtonClicked(keyword, message);
}

TEST_F(AlphabetCipherTest, GivenKeyYellowWhenDecryptClickedThenSetOutputStringIsCalledWithDecryptedString)
{
    QString expectedEncryption = "encryptthis";
    QString keyword = "yellow";
    QString message = "crncmlrxstg";

    EXPECT_CALL(WindowMock, SetOutputString(expectedEncryption));

    WindowMock.EmitDecryptButtonClicked(keyword, message);
}

TEST_F(AlphabetCipherTest, GivenKeyBlueWhenDecryptClickedThenSetOutputStringIsCalledWithDecryptedString)
{
    QString expectedEncryption = "hellofriend";
    QString keyword = "blue";
    QString message = "ipfppqlmfyx";

    EXPECT_CALL(WindowMock, SetOutputString(expectedEncryption));

    WindowMock.EmitDecryptButtonClicked(keyword, message);
}


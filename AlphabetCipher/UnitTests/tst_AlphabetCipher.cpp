
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

// TODO: Add functionality to allow handling spaces and capital letters
TEST_F(AlphabetCipherTest, GivenUppercaseKeyWhenEncryptClickedThenSetOutputStringIsCalledWithLowercaseEncryptedString)
{
    QString expectedEncryption = "crncmlrxstg";
    QString keyword = "YELLOW";
    QString message = "encryptthis";

    EXPECT_CALL(WindowMock, SetOutputString(expectedEncryption));

    WindowMock.EmitEncryptButtonClicked(keyword, message);
}

TEST_F(AlphabetCipherTest, GivenUppercaseMessageWhenEncryptClickedThenSetOutputStringIsCalledWithLowercaseEncryptedString)
{
    QString expectedEncryption = "crncmlrxstg";
    QString keyword = "YELLOW";
    QString message = "ENCRYPTTHIS";

    EXPECT_CALL(WindowMock, SetOutputString(expectedEncryption));

    WindowMock.EmitEncryptButtonClicked(keyword, message);
}

TEST_F(AlphabetCipherTest, GivenUppercaseKeyWhenDecryptClickedThenSetOutputStringIsCalledWithLowercaseDecryptedString)
{
    QString expectedEncryption = "encryptthis";
    QString keyword = "YELLOW";
    QString message = "crncmlrxstg";

    EXPECT_CALL(WindowMock, SetOutputString(expectedEncryption));

    WindowMock.EmitDecryptButtonClicked(keyword, message);
}

TEST_F(AlphabetCipherTest, GivenUppercaseMessageWhenDecryptClickedThenSetOutputStringIsCalledWithLowercaseDecryptedString)
{
    QString expectedEncryption = "hellofriend";
    QString keyword = "blue";
    QString message = "IPFPPQLMFYX";

    EXPECT_CALL(WindowMock, SetOutputString(expectedEncryption));

    WindowMock.EmitDecryptButtonClicked(keyword, message);
}

TEST_F(AlphabetCipherTest, GivenKeyWithSpacesWhenEncryptClickedThenSetOutputStringIsCalledWithEncryptedStringUsingKeyWithRemovedSpaces)
{
    QString expectedEncryption = "crncmlrxstg";
    QString keyword = "y ell   ow";
    QString message = "encryptthis";

    EXPECT_CALL(WindowMock, SetOutputString(expectedEncryption));

    WindowMock.EmitEncryptButtonClicked(keyword, message);
}

TEST_F(AlphabetCipherTest, GivenMessageWithSpacesWhenEncryptClickedThenSetOutputStringIsCalledWithEncryptedStringWithRemovedSpaces)
{
    QString expectedEncryption = "ipfppqlmfyx";
    QString keyword = "bl ue";
    QString message = "hello   friend";

    EXPECT_CALL(WindowMock, SetOutputString(expectedEncryption));

    WindowMock.EmitEncryptButtonClicked(keyword, message);
}

TEST_F(AlphabetCipherTest, GivenKeyWithSpacesWhenDecryptClickedThenSetOutputStringIsCalledWithDecryptedStringUsingKeyWithRemovedSpaces)
{
    QString expectedEncryption = "encryptthis";
    QString keyword = "yel low";
    QString message = "crncmlrxstg";

    EXPECT_CALL(WindowMock, SetOutputString(expectedEncryption));

    WindowMock.EmitDecryptButtonClicked(keyword, message);
}

TEST_F(AlphabetCipherTest, GivenMessageWithSpacesWhenDecryptClickedThenSetOutputStringIsCalledWithDecryptedStringWithRemovedSpaces)
{
    QString expectedEncryption = "hellofriend";
    QString keyword = "blue ";
    QString message = "ipfp pqlmf  yx";

    EXPECT_CALL(WindowMock, SetOutputString(expectedEncryption));

    WindowMock.EmitDecryptButtonClicked(keyword, message);
}

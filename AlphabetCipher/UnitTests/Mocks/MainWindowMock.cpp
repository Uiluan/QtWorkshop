#include "MainWindowMock.h"

MainWindowMock::MainWindowMock()
{

}

void MainWindowMock::EmitEncryptButtonClicked(const QString keyword, const QString message)
{
    emit EncryptButtonClicked(keyword, message);
}

void MainWindowMock::EmitDecryptButtonClicked(const QString keyword, const QString message)
{
    emit DecryptButtonClicked(keyword, message);
}

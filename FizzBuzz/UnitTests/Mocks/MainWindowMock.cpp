#include "MainWindowMock.h"

MainWindowMock::MainWindowMock()
{

}

void MainWindowMock::EmitCalculateButtonClicked(const int count)
{
    emit CalculateButtonClicked(count);
}

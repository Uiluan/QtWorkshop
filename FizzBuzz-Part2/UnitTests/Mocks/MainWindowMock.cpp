#include "MainWindowMock.h"

MainWindowMock::MainWindowMock()
{

}

void MainWindowMock::EmitCalculateButtonClicked(const int count, const int fizzValue, const int buzzValue)
{
    emit CalculateButtonClicked(count, fizzValue, buzzValue);
}

#include "FizzBuzzApp.h"
#include "FizzBuzz/FizzBuzz.h"
#include "MainWindow/MainWindow.h"

FizzBuzzApp::FizzBuzzApp(MainWindow& window, QObject *parent)
    : QObject(parent)
    , Window(&window)
{
    QObject::connect(Window, &MainWindow::CalculateButtonClicked, this, &FizzBuzzApp::OnCalculateButtonClicked);
}

void FizzBuzzApp::Run()
{
    Window->show();
}

void FizzBuzzApp::OnCalculateButtonClicked(const int count)
{
    FizzBuzz fizzBuzzCalculator;

    QStringList outputList = fizzBuzzCalculator.DetermineOutputList(count);
    Window->SetOutputList(outputList);
}

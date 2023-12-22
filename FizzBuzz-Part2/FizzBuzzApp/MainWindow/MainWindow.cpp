#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QPushButton>

MainWindow::MainWindow()
    : Ui(new Ui::MainWindow)
    , ListViewModel(new QStringListModel(this))
{
    Ui->setupUi(this);

    connect(Ui->CalculateButton, &QPushButton::clicked, this, &MainWindow::OnCalculateButtonClicked);
}

MainWindow::~MainWindow()
{
    delete Ui;
    delete ListViewModel;
}

void MainWindow::SetOutputList(QStringList &testList)
{
    ListViewModel->setStringList(testList);
    Ui->OutputList->setModel(ListViewModel);
}

void MainWindow::OnCalculateButtonClicked()
{
    emit CalculateButtonClicked(Ui->CountEntryBox->value(), Ui->FizzValueSpinBox->value(), Ui->BuzzValueSpinBox->value());
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , Ui(new Ui::MainWindow)
    , ListViewModel(new QStringListModel(this))
{
    Ui->setupUi(this);

    connect(Ui->CalculateButton, &QPushButton::clicked, this, &MainWindow::OnCalculateButtonClicked);
}

MainWindow::~MainWindow()
{
    delete Ui;
}

void MainWindow::SetOutputList(QStringList &testList)
{
    ListViewModel->setStringList(testList);
    Ui->OutputList->setModel(ListViewModel);
}

void MainWindow::OnCalculateButtonClicked()
{
    emit CalculateButtonClicked(Ui->CountEntryBox->value());
}


#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , Ui(new Ui::MainWindow)
{
    Ui->setupUi(this);
    SetUpHeaders();
    ConnectUiObjects();
}

MainWindow::~MainWindow()
{
    delete Ui;
}

void MainWindow::SetOutputString(const QString &message)
{
    Ui->OutputMessageLabel->setText(message);
}

void MainWindow::OnEncryptButtonClicked()
{
    emit EncryptButtonClicked(Ui->KeywordEditor->text(), Ui->InputMessageEditor->text());
}

void MainWindow::OnDecryptButtonClicked()
{
    emit DecryptButtonClicked(Ui->KeywordEditor->text(), Ui->InputMessageEditor->text());
}

void MainWindow::SetUpHeaders()
{
    QFont font("Arial", 12, QFont::Bold);
    SetUpKeywordHeader(font);
    SetUpInputHeader(font);
    SetUpOutputHeader(font);
}

void MainWindow::SetUpKeywordHeader(QFont &font)
{
    Ui->KeywordHeaderLabel->setFont(font);
    Ui->KeywordHeaderLabel->setText(QString("Keyword"));
}

void MainWindow::SetUpInputHeader(QFont &font)
{
    Ui->InputHeaderLabel->setFont(font);
    Ui->InputHeaderLabel->setText(QString("Input Text (No Spaces)"));
}

void MainWindow::SetUpOutputHeader(QFont &font)
{
    Ui->OutputHeaderLabel->setFont(font);
    Ui->OutputHeaderLabel->setText(QString("Encrypted Text"));
}

void MainWindow::ConnectUiObjects()
{
    connect(Ui->EncryptButton, &QPushButton::clicked, this, &MainWindow::OnEncryptButtonClicked);
    connect(Ui->DecryptButton, &QPushButton::clicked, this, &MainWindow::OnDecryptButtonClicked);
}


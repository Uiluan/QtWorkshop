#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MainWindowInterface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public MainWindowInterface
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
    void SetOutputString(const QString& message) override;

private slots:
    void OnEncryptButtonClicked();
    void OnDecryptButtonClicked();

private:
    void SetUpHeaders();
    void SetUpKeywordHeader(QFont& font);
    void SetUpInputHeader(QFont& font);
    void SetUpOutputHeader(QFont& font);
    void ConnectUiObjects();

    Ui::MainWindow *Ui;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetOutputString(const QString& message);

signals:
    void EncryptButtonClicked(const QString keyword, const QString message);
    void DecryptButtonClicked(const QString keyword, const QString message);

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

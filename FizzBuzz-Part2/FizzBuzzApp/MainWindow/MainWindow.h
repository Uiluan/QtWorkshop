#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MainWindowInterface.h"
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public MainWindowInterface
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();
    void SetOutputList(QStringList& list) override;

private slots:
    void OnCalculateButtonClicked();

private:
    Ui::MainWindow *Ui;
    QStringListModel *ListViewModel;
};
#endif // MAINWINDOW_H

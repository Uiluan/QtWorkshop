#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetOutputList(QStringList& list);

signals:
    void CalculateButtonClicked(const int count);

private slots:
    void OnCalculateButtonClicked();

private:
    Ui::MainWindow *Ui;
    QStringListModel *ListViewModel;
};
#endif // MAINWINDOW_H

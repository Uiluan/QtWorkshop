#ifndef MAINWINDOWINTERFACE_H
#define MAINWINDOWINTERFACE_H

#include <QMainWindow>

class MainWindowInterface : public QMainWindow
{
    Q_OBJECT

public:
    virtual void SetOutputList(QStringList& list) = 0;

signals:
    void CalculateButtonClicked(const int count);
};

#endif // MAINWINDOWINTERFACE_H

#ifndef MAINWINDOWINTERFACE_H
#define MAINWINDOWINTERFACE_H

#include <QMainWindow>

class MainWindowInterface : public QMainWindow
{
    Q_OBJECT

public:
    virtual void SetOutputString(const QString& message) = 0;

signals:
    void EncryptButtonClicked(const QString keyword, const QString message);
    void DecryptButtonClicked(const QString keyword, const QString message);
};

#endif // MAINWINDOWINTERFACE_H

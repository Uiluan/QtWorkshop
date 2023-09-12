#include "MainWindow/MainWindow.h"
#include "AlphabetCipher/AlphabetCipher.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    AlphabetCipher* cipher = new AlphabetCipher(window, &app);
    cipher->Run();

    return app.exec();
}

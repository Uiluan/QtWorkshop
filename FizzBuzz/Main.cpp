#include "FizzBuzzApp/FizzBuzzApp.h"
#include "MainWindow/MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    FizzBuzzApp *runner = new FizzBuzzApp(window, &app);
    runner->Run();

    return app.exec();
}

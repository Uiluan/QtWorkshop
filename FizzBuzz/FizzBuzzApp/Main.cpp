#include "FizzBuzz/FizzBuzz.h"
#include "MainWindow/MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    FizzBuzz *runner = new FizzBuzz(window);
    runner->Run();

    return app.exec();
}

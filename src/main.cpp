#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName("CurrencyConverter");
    QApplication::setOrganizationName("StudentLab");

    MainWindow window;
    window.show();

    return app.exec();
}
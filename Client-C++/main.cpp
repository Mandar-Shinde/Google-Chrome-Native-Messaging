/**
* Title               : Google Chrome Native Messaging API Qt C++ Client
* Author              : Mandar Shinde
* Interface           : GUI
* IDE                 : Qt5.4
* Operating System    : Windows 10
*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow * w = new MainWindow();
    w->show();
    w->setWindowTitle(QString("EPI纳新管理系统"));

    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    w.setFixedSize(1366, 768);
    w.show();
    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QThread>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyUdpSocket socket_s("sender");
    MyUdpSocket socket_l("listner");


    QThread thr_s;
    socket_s.moveToThread(&thr_s);
    thr_s.start();
    socket_s.bind_new_socket();

    QThread thr_l;
    socket_l.moveToThread(&thr_l);
    thr_l.start();
    socket_l.bind_new_socket();

    MainWindow w;
    w.show();

    QObject::connect(&w,SIGNAL(new_bind()),
            &socket_l,SLOT(bind_new_socket()));
    QObject::connect(&w,SIGNAL(new_bind()),
            &socket_s,SLOT(bind_new_socket()));



    return a.exec();
}

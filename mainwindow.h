#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myudpsocket.h"
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    Ui::MainWindow *ui;
//    MyUdpSocket *socket;
public slots:
    void on_pushButton();
signals:
    void new_bind();
};

#endif // MAINWINDOW_H

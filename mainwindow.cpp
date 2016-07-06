#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    socket=new MyUdpSocket();
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton()
{
    qDebug() <<"MainWindow::on_pushButton()>>";
    emit new_bind();
//    socket->bind_new_socket();
}

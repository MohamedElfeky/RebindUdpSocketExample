#ifndef MYUDPSOCKET_H
#define MYUDPSOCKET_H
#include <QUdpSocket>
#include <QObject>
#include <QDebug>

class MyUdpSocket : public QObject
{
    Q_OBJECT

    QUdpSocket* socket;
    QString defName;
public:
    explicit MyUdpSocket(QString defName, QObject *parent = 0);
     ~MyUdpSocket();
signals:
    void sgnSocketBindRez(bool);
public slots:
    void listenMessage();
    bool bind_new_socket();
};

#endif // MYUDPSOCKET_H

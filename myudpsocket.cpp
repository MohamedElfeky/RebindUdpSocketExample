#include "myudpsocket.h"

MyUdpSocket::MyUdpSocket(QString defName,QObject *parent) :
    QObject(parent),socket(0),defName(defName)
{

}

MyUdpSocket::~MyUdpSocket()
{
    if(socket) {
        socket->close();
        delete socket;
    }
}

void MyUdpSocket::listenMessage()
{
    qDebug() <<"listenMessage()---------------------------------------------------";
    QHostAddress sender;
    quint16 senderPort;
    if(socket) {
        while(socket->hasPendingDatagrams()) {
            qDebug() << "listner hasPendingDatagram";

            int bufSize = socket->pendingDatagramSize();
            char* message = new char[bufSize]; //читаем в нее из сокета

            int readSize = socket->readDatagram(message,
                                                bufSize, &sender, &senderPort);

            qDebug() <<"new msg size"<<readSize<<
                       sender.toString()<<"port"<<senderPort;
            delete [] message;//;
        }
    }
}

bool MyUdpSocket::bind_new_socket()
{
    qDebug() <<"try rebind soket"<< defName ;
    if(socket) {
        socket->close();
        delete socket;
    }
    socket=new QUdpSocket();
    if(socket){

        QString myHost="192.168.0.2";
        QHostAddress hostaddr(myHost);
        quint32 myport=1201;
        bool socketBind = socket->bind(hostaddr,
                                       myport,
        QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);

        if(socketBind ) {
            if(defName=="listner")
                connect(socket, SIGNAL(readyRead()), this, SLOT(listenMessage()));//,Qt::DirectConnection);

            qDebug() << defName <<"NEW SOCKET port: " << myport
                     << ", ip: " << myHost << "bind success.";
            //sgnSocketBindRez(true);
        } else {
            qDebug() << defName << "NEW SOCKET port: " << myport
                     << ", ip: " << myHost << ": не успешно привязан .";
            socket->close();
            //sgnSocketBindRez(false);
        }
    }
    else
        qDebug() << "socket ERROR";
}

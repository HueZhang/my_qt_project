#include "mythread.h"

MyThread::MyThread(QTcpSocket *s)
{
    socket = s;
}

void MyThread::run()
{

    connect(socket,&QTcpSocket::readyRead,this,&MyThread::clientInfo);
}

void MyThread::clientInfo()
{
    socket->readAll();

}

#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QTcpSocket *s);
    void run();

signals:

public slots:
    void clientInfo();

private:
    QTcpSocket *socket;

};

#endif // MYTHREAD_H

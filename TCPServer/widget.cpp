#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 创建
    server = new QTcpServer;

    server->listen(QHostAddress::AnyIPv4,8000);
    // 客户端发起连接，server发出信号
    connect(server,&QTcpServer::newConnection,this,&Widget::newClientHandle);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newClientHandle()
{
    // 建立tcp连接
    QTcpSocket *socket = server->nextPendingConnection();


    ui->lineEdit->setText(socket->peerAddress().toString()); // 获取客户端地址
    ui->lineEdit_2->setText(QString::number(socket->peerPort()));// 获取端口号

    // 服务端收到客户端发送的消息
    connect(socket,&QTcpSocket::readyRead,this,&Widget::clientInfo);
}

void Widget::clientInfo()
{
    // 获取信号的发出者
    QTcpSocket *s = (QTcpSocket *)sender();

    ui->msg_edit->setText(QString( s->readAll()));
}

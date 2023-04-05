#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket = new QTcpSocket;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_cancel_btn_clicked()
{
    this->close();
}

void Widget::on_connect_btn_clicked()
{
    // 获取IP和port
    QString IP = ui->ipEdit->text();
    QString PORT = ui->portEdit->text();

    // 连接
    socket->connectToHost(QHostAddress(IP),PORT.toShort());

    //连接成功
    connect(socket,&QTcpSocket::connected,[this]()
    {
        QMessageBox::information(this,"tips","connect success");
        this->hide();

        //Chat c; // 局部变量，在栈空间上，结束即销毁
        Chat *c = new  Chat(socket); // 创建在堆上
        //c.show();
        c->show();
    });

    // 连接失败
    connect(socket,&QTcpSocket::disconnected,[this]()
    {
       QMessageBox::information(this,"tips","connect error");
    });
}

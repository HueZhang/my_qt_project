#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QTcpSocket *s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    socket = s;
}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_clr_btn_clicked()
{
    ui->lineEdit->clear();
}

void Chat::on_send_btn_clicked()
{
    QByteArray ba;
    ba.append(ui->lineEdit->text());
    socket->write(ba);
}

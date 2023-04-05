#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    picId = 2;
    QPixmap pix("D:\\pictures\\messi.jpg");
    ui->label->setPixmap(pix);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_start_btn_clicked()
{
    // 开启定时器，返回定时器编号
    myTimerId = this->startTimer(TIMEOUT);
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() != myTimerId)
        return;
    // 图片路径
    QString path("D:\\pictures\\");
    path += QString::number(picId);
    path += ".jpg";

    QPixmap pix(path);
    ui->label->setPixmap(pix);

    picId++;
    if(picId == 6)
        picId = 2;
}

void Widget::on_stop_btn_clicked()
{
    //
    this->killTimer(myTimerId);
}

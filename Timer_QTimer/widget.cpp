#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 构造函数，新建timer对象
    timer = new QTimer;
    // 使用QImage传入图片
    QImage img;
    img.load("D:\\pictures\\messi.jpg");
    //
    ui->label->setPixmap(QPixmap::fromImage(img));
    picID = 2;
    connect(timer,&QTimer::timeout,this,&Widget::showPIC);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    // 可以直接使用timer的start方法
    timer->start(TIMEOUT);
}

void Widget::showPIC()
{
    QString path("D:\\pictures\\");
    // int转为string
    path += QString::number(picID);
    path += ".jpg";

    QImage img;
    img.load(path);

    ui->label->setPixmap(QPixmap::fromImage(img));
    picID++;
    if(picID == 6)
        picID = 2;
}

void Widget::on_pushButton_2_clicked()
{
    timer->stop();
}

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 连接信号与槽 发出信号  信号 处理信号 处理
    connect(ui->cmdLineEdit,SIGNAL(returnPressed()),this,SLOT(on_commitbtn_clicked()));

    // 地址方式
    connect(ui->cancelbtn,&QPushButton::clicked,this,&Widget::on_cancelbtn_clicked);

    connect(ui->browbtn,&QPushButton::clicked,[this]()
    {
       QMessageBox::information(this,"浏览","fuckyou");
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_commitbtn_clicked()
{
    //获取数据
    QString program = ui->cmdLineEdit->text();
    // 创建process对象
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program);
}

void Widget::on_cancelbtn_clicked()
{
    this->close();
}

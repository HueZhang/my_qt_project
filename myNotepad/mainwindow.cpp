#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->act_new,&QAction::triggered,this,&MainWindow::actNewSlot);
    connect(ui->act_open,&QAction::triggered,this,&MainWindow::actOpenSlot);
    connect(ui->act_save,&QAction::triggered,this,&MainWindow::actSaveSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actNewSlot()
{
    // 点击新建，先清空
    ui->textEdit->clear();
    this->setWindowTitle("新建文本文档.txt");

}

void MainWindow::actOpenSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     QCoreApplication::applicationFilePath(),
                                                     "*.cpp");
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"warn","no file open");
    }else {
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        ui->textEdit->setPlainText(QString(ba));
        file.close();
    }
}

void MainWindow::actSaveSlot()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save File"),
                                                    QCoreApplication::applicationFilePath());
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"warn","no file save");
    }else {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        QByteArray ba;
        ba.append(ui->textEdit->toPlainText());
        file.write(ba);
        file.close();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    // 如果同时按下ctrl和s
    if(k->modifiers() == Qt::ControlModifier && k->key() == Qt::Key_S)
    {
        actSaveSlot();
    }
}

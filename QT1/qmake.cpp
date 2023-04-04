#include<QApplication>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout> // 水平
#include<QVBoxLayout> // 垂直
#include<QWidget>


int main(int argc,char *argv[])
{
    // 创建应用程序
    QApplication app(argc,argv);

    // 创建对象
    QLabel *infoLabel = new QLabel;
    QLabel *openLabel = new QLabel;
    QLineEdit *cmdLineEdit = new QLineEdit;
    QPushButton *commitButton = new QPushButton;
    QPushButton *cancelButton = new QPushButton;
    QPushButton *browerButton = new QPushButton;

    // 设置
    infoLabel->setText("set "); 
    openLabel->setText("set ");
    cmdLineEdit->setText("set ");
    commitButton->setText("set ");
    cancelButton->setText("set ");
    browerButton->setText("set ");

    // 布局
    // 水平布局
    QHBoxLayout *cmdLayout = new QHBoxLayout;
    cmdLayout->addWidget(openLabel);
    cmdLayout->addWidget(cmdLineEdit);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addWidget(commitButton);
    btnLayout->addWidget(cancelButton);
    btnLayout->addWidget(browerButton);

    // 垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(infoLabel);
    mainLayout->addLayout(cmdLayout);
    mainLayout->addLayout(btnLayout);

    // 窗口
    QWidget window;
    window.setLayout(mainLayout);
    window.setWindowTitle("tttt");
    window.show();
    


    return app.exec();
}
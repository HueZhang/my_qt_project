#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 槽
private slots:
    void on_commitbtn_clicked();

    void on_cancelbtn_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

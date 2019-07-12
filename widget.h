#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void changeMoney(int n);
    void returnMoney();
    int money {0};

private slots:
    void on_pb_10_clicked();

    void on_pb_50_clicked();

    void on_pb_100_clicked();

    void on_pb_500_clicked();

    void on_pb_americano_clicked();

    void on_pb_tea_clicked();

    void on_pb_coke_clicked();

    void on_pb_return_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

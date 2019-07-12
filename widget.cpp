#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::returnMoney(void)
{
    int a = money / 500;
    int b = (money % 500 ) / 100;
    int c = ((money % 500 ) % 100 ) / 50;
    int d = (((money % 500 ) % 100 ) % 50) / 10;

    QString R = QString("Return Coin is\n500won : %1\n100won : %2\n50won : %3\n10won : %4").arg(a).arg(b).arg(c).arg(d);

    QMessageBox msg;
    msg.information(nullptr, "Return Coin", R);

    money =0;
    ui->lcdNumber->display(money);
}

void Widget::changeMoney(int n)
{
        ui->lcdNumber->display(money += n);

        if( money < 100)
        {
            ui->pb_coke->setDisabled(1);
            ui->pb_tea->setDisabled(1);
            ui->pb_americano->setDisabled(1);
        }
        else if ( money < 150 )
        {
            ui->pb_coke->setDisabled(1);
            ui->pb_tea->setDisabled(1);
            ui->pb_americano->setEnabled(1);
        }
        else if ( money < 200)
        {
            ui->pb_coke->setDisabled(1);
            ui->pb_tea->setEnabled(1);
            ui->pb_americano->setEnabled(1);
        }
        else
        {
            ui->pb_coke->setEnabled(1);
            ui->pb_tea->setEnabled(1);
            ui->pb_americano->setEnabled(1);
        }

        if(money > 0)
            ui->pb_return->setEnabled(1);
        else
            ui->pb_return->setDisabled(1);

}

void Widget::on_pb_10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb_50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb_100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb_500_clicked()
{
    changeMoney(500);
}

void Widget::on_pb_americano_clicked()
{
     changeMoney(-100);
}

void Widget::on_pb_tea_clicked()
{
     changeMoney(-150);
}

void Widget::on_pb_coke_clicked()
{
     changeMoney(-200);
}

void Widget::on_pb_return_clicked()
{
    returnMoney();
}

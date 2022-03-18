#include "myWidget.h"


myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    MyPushButton* btn = new MyPushButton(this);
    btn->setText(QString::fromLocal8Bit("打开窗口"));
    this->resize(800, 600);
    this->connect(btn, &QPushButton::clicked,btn, &MyPushButton::changeIcon);
}

myWidget::~myWidget()
{

}

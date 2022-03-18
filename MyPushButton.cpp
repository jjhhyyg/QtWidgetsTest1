#include "MyPushButton.h"

MyPushButton::MyPushButton(QWidget* parent) :QPushButton(parent)
{
	flag = false;
}

void MyPushButton::changeIcon() 
{
	flag = !flag;
	if (flag == false) {
		this->setText(QString::fromLocal8Bit("打开窗口"));
	}
	else {
		this->setText(QString::fromLocal8Bit("关闭窗口"));
	}
}

MyPushButton::~MyPushButton()
{

}
#include "MyPushButton.h"

MyPushButton::MyPushButton(QWidget* parent) :QPushButton(parent)
{
	flag = false;
}

void MyPushButton::changeIcon() 
{
	flag = !flag;
	if (flag == false) {
		this->setText(QString::fromLocal8Bit("�򿪴���"));
	}
	else {
		this->setText(QString::fromLocal8Bit("�رմ���"));
	}
}

MyPushButton::~MyPushButton()
{

}
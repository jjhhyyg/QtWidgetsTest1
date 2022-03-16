#include "MyPushButton.h"

MyPushButton::MyPushButton(QWidget* parent) :QPushButton(parent)
{
	qDebug() << QString::fromLocal8Bit("构造我的按钮类");
}

MyPushButton::~MyPushButton()
{
	qDebug() << QString::fromLocal8Bit("析构我的按钮类");
}
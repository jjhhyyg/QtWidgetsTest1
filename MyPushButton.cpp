#include "MyPushButton.h"

MyPushButton::MyPushButton(QWidget* parent) :QPushButton(parent)
{
	qDebug() << QString::fromLocal8Bit("�����ҵİ�ť��");
}

MyPushButton::~MyPushButton()
{
	qDebug() << QString::fromLocal8Bit("�����ҵİ�ť��");
}
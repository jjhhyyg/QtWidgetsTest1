#include "Student.h"

Student::Student(QObject* parent):QObject(parent)
{

}

void Student::treat() 
{
	qDebug() << QString::fromLocal8Bit("请老师吃饭").toUtf8().data();
}

void Student::treat(QString foodName)
{
	// QString默认有引号
	// qDebug() << QString::fromLocal8Bit("请老师吃") << foodName;
	// 转换为char*就可以消除引号：先转成QByteArray，再转换为char*
	qDebug() << QString::fromLocal8Bit("请老师吃").toUtf8().data() << foodName.toUtf8().data();
}
#include "Student.h"

Student::Student(QObject* parent):QObject(parent)
{

}

void Student::treat() 
{
	qDebug() << QString::fromLocal8Bit("����ʦ�Է�");
}
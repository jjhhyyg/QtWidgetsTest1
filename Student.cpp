#include "Student.h"

Student::Student(QObject* parent):QObject(parent)
{

}

void Student::treat() 
{
	qDebug() << QString::fromLocal8Bit("����ʦ�Է�").toUtf8().data();
}

void Student::treat(QString foodName)
{
	// QStringĬ��������
	// qDebug() << QString::fromLocal8Bit("����ʦ��") << foodName;
	// ת��Ϊchar*�Ϳ����������ţ���ת��QByteArray����ת��Ϊchar*
	qDebug() << QString::fromLocal8Bit("����ʦ��").toUtf8().data() << foodName.toUtf8().data();
}
#pragma once
#include <qObject>
class Teacher :
	public QObject
{
	Q_OBJECT
public:
	explicit Teacher(QObject* parent = 0);
signals:
	// �Զ����źţ�д��signals��
	// ����ֵ��void��ֻ��Ҫ����������Ҫʵ��
	// �����в�������������
	void hungry();
	void hungry(QString foodName);
public slots:

};


#pragma once
#include <QObject>
#include <QDebug>

class Student:
	public QObject
{
	Q_OBJECT
public:
	explicit Student(QObject* parent = 0);
signals:

public slots:
	// �� ����д��public��ȫ�֡�public slots�У����ڵ�QT�汾ֻ��д��public slots��
	// ����ֵΪvoid����Ҫ������Ҳ��Ҫʵ��
	// �����в�������������
	void treat();
};


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
	// 槽 可以写在public、全局、public slots中，早期的QT版本只能写在public slots中
	// 返回值为void，需要声明，也需要实现
	// 可以有参数，可以重载
	void treat();
};


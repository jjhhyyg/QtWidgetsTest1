#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <Qpushbutton>
#include <QDebug>

class MyPushButton : public QPushButton
{
	Q_OBJECT
public:
	explicit MyPushButton(QWidget* parent = 0);
	~MyPushButton();
private:
	bool flag; //Ϊfalseʱ��ʾ���������ڡ���Ϊtrueʱ��ʾ���رմ��ڡ�
	QWidget* widgets; //�Ӵ���ָ��
signals:

public slots:
	void changeIcon();
	void windowControl();
};

#endif // MYPUSHBUTTON_H

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
	bool flag; //为false时显示“弹出窗口”，为true时显示“关闭窗口”
	QWidget* widgets; //子窗口指针
signals:

public slots:
	void changeIcon();
	void windowControl();
};

#endif // MYPUSHBUTTON_H

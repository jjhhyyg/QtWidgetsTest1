#pragma once

#include <QtWidgets/QWidget>
#include "ui_myWidget.h"
#include <Qpushbutton>
#include "MyPushButton.h"
#include <QDebug>
#include "Teacher.h"
#include "Student.h"

class myWidget : public QWidget
{
    Q_OBJECT // 宏， 允许类中使用信号和槽的机制

public:
    myWidget(QWidget *parent = Q_NULLPTR);
    ~myWidget();
private:
    Teacher* t;
    Student* s;

    void afterClass();
};

﻿#pragma once

#include <QtWidgets/QWidget>
#include "ui_myWidget.h"
#include <Qpushbutton>
#include <QDebug>

class myWidget : public QWidget
{
    Q_OBJECT // 宏， 允许类中使用信号和槽的机制

public:
    myWidget(QWidget *parent = Q_NULLPTR);
    ~myWidget();
private:
    // Ui::myWidgetClass ui;
};

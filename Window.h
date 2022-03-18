#pragma once

#include <QtWidgets/QMainWindow>
#include <ui_Window.h>
#include <qdialog.h>
#include <qaction.h>
#include <qdebug.h>

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget* parent = Q_NULLPTR);
private:
    Ui::WindowClass ui;
};

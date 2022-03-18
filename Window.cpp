#include "Window.h"


Window::Window(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // 添加菜单栏选项图标
    ui.actionnew_File->setIcon(QIcon(":/Photo/new-file.png"));
    ui.actionopen_File->setIcon(QIcon(":/Photo/document.png"));

    // 点击新建按钮，弹出一个对话框
    connect(ui.actionnew_File, &QAction::triggered, [this]() {
        // 对话框的分类：模态对话框和非模态对话框
        // 非模态对话框：打开后可对其他窗口进行操作；模态对话框则不行

        // 模态对话框创建
        QDialog dialog(this);
        qDebug() << QString::fromLocal8Bit("模态对话框弹出了");
        dialog.exec();
        });
    connect(ui.actionopen_File, &QAction::triggered, [this]() {
        // 非模态对话框创建
        QDialog* dialog = new QDialog(this);
        qDebug() << QString::fromLocal8Bit("非模态对话框弹出了");
        dialog->show();
        // 设置关闭时删除该对象
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        });

}

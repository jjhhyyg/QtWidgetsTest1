#include "Window.h"


Window::Window(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // ��Ӳ˵���ѡ��ͼ��
    ui.actionnew_File->setIcon(QIcon(":/Photo/new-file.png"));
    ui.actionopen_File->setIcon(QIcon(":/Photo/document.png"));

    // ����½���ť������һ���Ի���
    connect(ui.actionnew_File, &QAction::triggered, [this]() {
        // �Ի���ķ��ࣺģ̬�Ի���ͷ�ģ̬�Ի���
        // ��ģ̬�Ի��򣺴򿪺�ɶ��������ڽ��в�����ģ̬�Ի�������

        // ģ̬�Ի��򴴽�
        QDialog dialog(this);
        qDebug() << QString::fromLocal8Bit("ģ̬�Ի��򵯳���");
        dialog.exec();
        });
    connect(ui.actionopen_File, &QAction::triggered, [this]() {
        // ��ģ̬�Ի��򴴽�
        QDialog* dialog = new QDialog(this);
        qDebug() << QString::fromLocal8Bit("��ģ̬�Ի��򵯳���");
        dialog->show();
        // ���ùر�ʱɾ���ö���
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        });

}

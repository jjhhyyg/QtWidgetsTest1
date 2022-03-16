#include "myWidget.h"


myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    // 创建第一个按钮
    //QPushButton* btn = new QPushButton;
    // 从顶层显示该按钮（会新建一个窗口）
    // btn->show();

    // 让btn对象依赖在myWidget窗口中
    // 设置父亲
    //btn->setParent(this);

    // 显示文本
    //btn->setText("hi!");


    // 创建第二个按钮：按照控件大小创建窗口
    QPushButton* btn2 = new QPushButton(QString::fromLocal8Bit("第二个按钮"), this);

    // 移动按钮坐标
    btn2->move(400, 300);

    // 重置窗口大小
    resize(800,600);

    // 设置窗口标题
    setWindowTitle(QString::fromLocal8Bit("第一个窗口"));

    // 设置固定窗口大小
    setFixedSize(600, 400);

    // 创建一个自己的按钮对象
    MyPushButton* myBtn = new MyPushButton;
    myBtn->setText(QString::fromLocal8Bit("我自己的按钮"));
    myBtn->move(200, 0);
    myBtn->setParent(this);

    // 需求：点击我的按钮，关闭窗口
    // 参数1：信号的发送者
    // 参数2：发送的信号（函数的地址）
    // 参数3：信号的接收者
    // 参数4：处理的槽
    connect(myBtn, &MyPushButton::clicked, this, &myWidget::close);

    // ui.setupUi(this);
}

myWidget::~myWidget()
{
    qDebug() << QString::fromLocal8Bit("myWidget的析构调用");
}

#include "myWidget.h"

// Teacher 老师类
// Student 学生类
// 下课后，老师会触发一个信号——饿了，学生响应信号——请客吃饭

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    // 创建一个老师对象（同时指定父亲）
    t = new Teacher(this);


    // 创建一个学生对象（同时指定父亲）
    s = new Student(this);

    // 连接带参数的信号和槽
    // 函数指针 -> 函数地址
    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSlot)(QString) = &Student::treat;
    this->connect(t, teacherSignal, s, studentSlot);

    // 调用下课函数
    // afterClass();

    // 点击一个下课的按钮，再触发下课（有参）
    QPushButton* btn = new QPushButton(QString::fromLocal8Bit("下课（有参）"),this);
    this->resize(600, 400);
    this->connect(btn,&QPushButton::clicked,this,&myWidget::afterClass);

    // 点击一个下课的按钮，再触发下课（无参），信号触发信号
    void(Teacher:: * teacherSignal2)(void) = &Teacher::hungry;
    void(Student:: * studentSlot2)(void) = &Student::treat;
    this->connect(t, teacherSignal2, s, studentSlot2);
    QPushButton* btn2 = new QPushButton(QString::fromLocal8Bit("下课（无参）"), this);
    btn2->move(200, 0);
    this->connect(btn2, &QPushButton::clicked, t, teacherSignal2);

    // 断开信号
    this->disconnect(btn, &QPushButton::clicked, this, &myWidget::afterClass);

    // 扩展：一个信号可以连接多个槽函数，多个信号可以连接同一个槽函数
    // 信号和槽的参数类型必须一一对应
    // 信号和槽的参数个数不一定一一对应，但槽的参数一定是信号的参数的子集
}

void myWidget::afterClass()
{
    // 下课了，调用后，触发老师饿了的信号
    // emit t->hungry();
    emit t->hungry(QString::fromLocal8Bit("宫保鸡丁"));
}

myWidget::~myWidget()
{
    
}

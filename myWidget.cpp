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
    // this->connect(t, teacherSignal, s, studentSlot);

    // QT4版本及以前的信号和槽连接方式
    // 有参
    this->connect(t, SIGNAL(hungry(QString)), s, SLOT(treat(QString)));

    // 调用下课函数
    // afterClass();

    // 点击一个下课的按钮，再触发下课（有参）
    QPushButton* btn = new QPushButton(QString::fromLocal8Bit("下课（有参）"),this);
    this->resize(600, 400);
    this->connect(btn, &QPushButton::clicked, this, &myWidget::afterClass);
    

    // 点击一个下课的按钮，再触发下课（无参），信号触发信号
    void(Teacher:: * teacherSignal2)(void) = &Teacher::hungry;
    void(Student:: * studentSlot2)(void) = &Student::treat;

    this->connect(t, teacherSignal2, s, studentSlot2);

    // QT4版本及以前的信号和槽连接方式
    // 无参
    // this->connect(t, SIGNAL(hungry()), s, SLOT(treat()));

    QPushButton* btn2 = new QPushButton(QString::fromLocal8Bit("下课（无参）"), this);
    btn2->move(200, 0);
    this->connect(btn2, &QPushButton::clicked, t, teacherSignal2);

    // 断开信号
    // this->disconnect(btn, &QPushButton::clicked, this, &myWidget::afterClass);

    // 扩展：一个信号可以连接多个槽函数，多个信号可以连接同一个槽函数
    // 信号和槽的参数类型必须一一对应
    // 信号和槽的参数个数不一定一一对应，但槽的参数一定是信号的参数的子集

    // lambda表达式
    // []中为"="表示值传递，为"&"表示引用传递，用这两个符号时可以使用lambda表达式所在作用于范围内所有可见的局部变量，包括this
    // []中为"this"时，函数体内可以使用lambda所在类中的成员变量
    // [=,&a,&b]表示除a和b按引用传递外，其他参数都按值传递
    // 在最后一对()前的内容都是函数的定义，()表示函数的引用
    // 当以值传递时，默认该变量不可修改，若要修改需要在第一个()后加上mutable关键字，但修改的只是该变量的副本而不是其本身
    // 返回值：默认为void，可以有一个return，要在第一个()后加上-><返回值类型>
    // 
    // 用途：在connect的时候，可以定义槽
    /*int ret = [=]() ->int{
        btn->setText("aaaa");
        return 1000;
    }();*/

    // 利用lambda实现点击按钮，关闭窗口（无参）
    QPushButton* btn3 = new QPushButton(QString::fromLocal8Bit("关闭窗口"), this);
    btn3->move(0, 200);
    this->connect(btn3, &QPushButton::clicked, this, [=]() {
        this->close();
        });

    // 利用lambda实现点击按钮，触发请客事件（有参）
    QPushButton* btn4 = new QPushButton(QString::fromLocal8Bit("请客吃宫保鸡丁"), this);
    btn4->move(200, 200);
    
    // PS: 第三个参数是this的时候可以省略不要
    this->connect(btn4, &QPushButton::clicked, s, [=]() {
        emit t->hungry(QString::fromLocal8Bit("宫保鸡丁"));
        btn4->setText(QString::fromLocal8Bit("请不动了"));
        });

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

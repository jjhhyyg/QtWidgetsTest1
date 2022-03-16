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

    // 老师饿了，学生请客的连接
    connect(t, &Teacher::hungry, s, &Student::treat);

    // 调用下课函数
    afterClass();
}

void myWidget::afterClass()
{
    // 下课了，调用后，触发老师饿了的信号
    emit t->hungry();
}

myWidget::~myWidget()
{
    
}

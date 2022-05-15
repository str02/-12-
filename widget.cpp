#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setMouseTracking(true);
    ui->openGLWidget->installEventFilter(this);


    connect(&time,SIGNAL(timeout()),this,SLOT(refreshTime()));

}

Widget::~Widget()
{
    delete ui;
}
//这个是虚函数重写 //信号因该是会给一个参数
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers()==Qt::ControlModifier)
    {
        //key数值（就是关键值）Key_T（这个变量对应的是T,t）
        if(event->key()==Qt::Key_T)
        {
            qDebug()<<"key T pressd";
        }
        //key数值（就是关键值）Key_Z（这个变量对应的是Z,z）
        if(event->key()==Qt::Key_Z)
        {
            qDebug()<<"key z pressd";
        }
    }

}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        qDebug()<<"鼠标左键按下";
    }
    if(event->button()==Qt::RightButton)
    {
        qDebug()<<"鼠标右键按下";
    }
    if(event->button()==Qt::MidButton)
    {
        qDebug()<<"鼠标中键按下";
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        qDebug()<<"鼠标左键松开";
    }
    if(event->button()==Qt::RightButton)
    {
        qDebug()<<"鼠标右键松开";
    }
    if(event->button()==Qt::MidButton)
    {
        qDebug()<<"鼠标中键松开";
    }
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        qDebug()<<QStringLiteral("鼠标左键双击按下");
        qDebug()<<"鼠标左键双击按下";
    }
    if(event->button()==Qt::RightButton)
    {
        qDebug()<<QStringLiteral( "鼠标右键双击按下");
    }
    if(event->button()==Qt::MidButton)
    {
        qDebug()<<QStringLiteral("鼠标中键双击按下");
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{

    //    QString posstr = QString(QStringLiteral("鼠标当前坐标为: %1")).arg(event->pos());
    //QString posstr =QStringLiteral("鼠标当前位置坐标为：");
    QString posstr;
    posstr.append("鼠标当前位置坐标为：");
    qDebug()<<posstr<<event->pos();

}

void Widget::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0)
    {
        qDebug()<<"滚轮往前推";
    }
    else
    {
        qDebug()<<"滚轮往后推";
    }
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->openGLWidget)
    {

        if(event->type()==QEvent::KeyPress)
        {
            QKeyEvent * keyEvent = static_cast<QKeyEvent*>(event);
            qDebug()<<"ate key press"<<keyEvent->key();
            return  true;
        }
        else
        {
            return  false;
        }
    }
    else
    {
    return Widget::eventFilter(watched,event);
    }
}

void Widget::timerEvent(QTimerEvent *event)
{
}

void Widget::refreshTime()
{
    Sleep(12);
}



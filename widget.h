#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include<QKeyEvent>
#include<QLineEdit>
#include <qwidget.h>
#include <QWidget>
#include<QDebug>
#include<QString>
#include<qobject.h>
#include<QObject>
#include<QEvent>
#include<QTimerEvent>
#include<QTimer>
namespace Ui {
class Widget;
}
class Widget : public QWidget
{
    Q_OBJECT


public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void wheelEvent(QWheelEvent *event);
    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual void timerEvent(QTimerEvent *event);


public slots :
    void refreshTime();
    
private:
    Ui::Widget *ui;
    QTimer time;
};

#endif // WIDGET_H

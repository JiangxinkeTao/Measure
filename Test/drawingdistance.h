#ifndef DRAWINGDISTANCE_H
#define DRAWINGDISTANCE_H

#include <QWidget>

//设置鼠标按下事件
#include <QMouseEvent>
//设置绘图事件的头文件
#include <QPaintEvent>
//设置点的头文件
#include <QPoint>
#include <qpoint.h>
#include "qpointer.h"

#include <QString>

namespace Ui {
class DrawingDistance;
}

class DrawingDistance : public QWidget
{
    Q_OBJECT

public:
    explicit DrawingDistance(QWidget *parent = 0);
    ~DrawingDistance();
    //关闭窗口的快捷键
    void keyPressEvent(QKeyEvent *);

    //鼠标在绘图窗口单击发生事件成员函数
    void mousePressEvent(QMouseEvent *event);
    //设置绘图事件
    void paintEvent(QPaintEvent *event);

signals:
    //构建信号，将点击屏幕的信号告诉主窗口，
    //要求主窗口更改A坐标值的内容
    void subsignal_Apoint(QString);
    //要求改变主窗口中的B坐标值内容
    void subsignal_Bpoint(QString);

private:
    Ui::DrawingDistance *ui;

public:
    QPoint Apoint;
    QPoint Bpoint;



};

#endif // DRAWINGDISTANCE_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "drawingdistance.h"

//捕捉窗口关闭信息
#include <QCloseEvent>

#include <QString>

//使用STL
#include <QVector>


namespace Ui {
class Widget;

}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    //捕捉窗口关闭信息
    void closeEvent( QCloseEvent *event);

public slots:
    void on_DrawingClicked_clicked();

    //定义槽函数，用于接受单击子窗口时候传来的信号，并且对其进行操作
    void subClickSlot_A(QString st);
    void subClickSlot_B(QString st);

public:
    //这部分是一些成员函数，主要是给 subClickSlot_B 处理使用的！
    //判断 “图上距离” 和 “测量距离” 是否为空；
    bool isMap_Measur_Empty();
    //获取上述的两个编辑框中的数值，并且将其赋值给比例尺中
    void Scale_number();

    //提取AB坐标点的数值并且返回
    QVector<QPoint> valueOfcord();


private:
    Ui::Widget *ui;
public:
    //第二个窗口是他的一个成员
    DrawingDistance *DrawAPointtoBPoint;


};

#endif // WIDGET_H

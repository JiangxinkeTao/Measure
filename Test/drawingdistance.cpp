#include "drawingdistance.h"
#include "ui_drawingdistance.h"
#include "widget.h"

#include <QKeyEvent>
//绘图设备头文件
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <qpoint.h>

#include <QString>
#include <QDebug>

//设置全局变量
QString APText;
QString BPText;

//设置全局变量
int clicknumber=0;

DrawingDistance::DrawingDistance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawingDistance)
{
    ui->setupUi(this);
}

DrawingDistance::~DrawingDistance()
{
    delete ui;
}

//绘图事件的成员函数
void DrawingDistance::paintEvent(QPaintEvent *event)
{
    //先创建画家对象
    QPainter painter_wangtao(this);
    //创建画笔
    QPen pen;
    //设置画笔的属性
    pen.setWidth(2);//画笔宽度
    pen.setColor(Qt::red);//画笔颜色
    //将画笔交给画家
    painter_wangtao.setPen(pen);

    //QPoint Apoint;
    //painter_wangtao.drawEllipse(Apoint,10,10);
    //painter_wangtao.drawLine(10,10,100,100);
    if(clicknumber!=0)
    {
        if(clicknumber%2==1)
        {
            painter_wangtao.drawEllipse(Apoint,5,5);
        }
        else
        {
            painter_wangtao.drawEllipse(Apoint,5,5);
            painter_wangtao.drawEllipse(Bpoint,5,5);
            painter_wangtao.drawLine(Apoint,Bpoint);
            painter_wangtao.drawLine(Apoint.x(),Apoint.y()
                                     ,Apoint.x(),Bpoint.y());
            painter_wangtao.drawLine(Bpoint.x(),Bpoint.y()
                                     ,Apoint.x(),Bpoint.y());
        }

    }


}

//单击鼠标绘图事件
void DrawingDistance::mousePressEvent(QMouseEvent *event)
{

    clicknumber++;
    /*
     * 单击次数记录，之后是需要删除的
    */
    //qDebug()<<clicknumber;

    //当鼠标单击绘图的子窗口时候将会发射信号,但是需要判断信号的给A还是B
    if(clicknumber%2==0)
    {
        //当在绘图窗口单击时候，首先绘制一个红色叉叉，表明绘图点的形成
        Bpoint = event->pos();
        QString bstemp_x=tr("%8").arg(Bpoint.x());
        QString bstemp_y=tr("%8").arg(Bpoint.y());
        QString bstemp=bstemp_x+" "+bstemp_y;

        emit subsignal_Bpoint(bstemp);

    }
    else
    {

        //当在绘图窗口单击时候，首先绘制一个红色叉叉，表明绘图点的形成
        Apoint = event->pos();

        QString astemp_x=tr("%8").arg(Apoint.x());
        QString astemp_y=tr("%8").arg(Apoint.y());
        QString astemp=astemp_x+" "+astemp_y;

        emit subsignal_Apoint(astemp);
    }

    update();

}

//设置绘图窗口关闭快捷键
void DrawingDistance::keyPressEvent(QKeyEvent *e)
{
    if(Qt::Key_Escape==e->key())
    {
        //设置关闭第二个窗口的快捷键
        this->close();


    }
}

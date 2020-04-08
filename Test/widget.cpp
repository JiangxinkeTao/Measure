#include "widget.h"
#include "ui_widget.h"
#include "drawingdistance.h"

//下面这部分是为了实现对桌面窗口的捕捉
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>

//窗口关闭捕捉头文件
#include <QCloseEvent>
#include <QPoint>
#include "qpoint.h"

#include <QString>
#include <QDebug>

//数学公式
#include "qmath.h"

//设置全局变量
extern QString APText;
extern QString BPText;

extern int clicknumber;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //对第二个窗口进行初始化
    //DrawingDistance *DrawAPointtoBPoint=new DrawingDistance;
    DrawAPointtoBPoint=new DrawingDistance;
    //但是不显示
    DrawAPointtoBPoint->hide();

    //将信号和槽关联起来 这是A信号的！！
    connect(DrawAPointtoBPoint,SIGNAL(subsignal_Apoint(QString)),
            this,SLOT(subClickSlot_A(QString)));
    //将信号和槽关联起来 这是B信号的！！
    connect(DrawAPointtoBPoint,SIGNAL(subsignal_Bpoint(QString)),
            this,SLOT(subClickSlot_B(QString)));


}


//判断测量窗口是否为空
bool Widget::isMap_Measur_Empty()
{
    QString stemp_t_1,stemp_t_2;
    stemp_t_1=ui->MapDistance->toPlainText();//图上距离
    stemp_t_2=ui->MeasureDistance->toPlainText();//测量距离
    if(stemp_t_1==""||stemp_t_2=="")
    {
        return false;
    }
    else
    {
        /*
        double m1=stemp_t_1.toDouble();
        double m2=stemp_t_2.toDouble();
        */
        return true;
    }

}

//将上述窗口中的数值赋值给比例尺
void Widget::Scale_number()
{
    if(isMap_Measur_Empty()==true)
    {
        QString stemp_t_1,stemp_t_2;
        stemp_t_1=ui->MapDistance->toPlainText();
        stemp_t_2=ui->MeasureDistance->toPlainText();

        double m1=stemp_t_1.toDouble();
        double m2=stemp_t_2.toDouble();

        double m=m1/m2;

        //QString ss=QString::num(m);

        ui->ScreenScale->setValue(m);
    }
}

//提取出坐标值
QVector<QPoint> Widget::valueOfcord()
{
    QVector<QPoint> P;

    //提取坐标值
    QString st_01= ui->APoint_text->toPlainText();
    QStringList s_01=st_01.split(" ");
    int apx=s_01[0].toInt();
    int apy=s_01[1].toInt();
    QPoint X_01(apx,apy);
    P.push_back(X_01);


    QString st_02=ui->BPoint_text->toPlainText();
    QStringList s_02=st_02.split(" ");
    int bpx=s_02[0].toInt();
    int bpy=s_02[1].toInt();
    QPoint X_02(bpx,bpy);
    P.push_back(X_02);

    return P;
}

//接受单击鼠标点击绘图子窗口的槽函数的实现 这是A窗口
void Widget::subClickSlot_A(QString st)
{
    ui->APoint_text->setText(st);

}

//接受单击鼠标绘图子窗口的槽函数的实现 这是B窗口
void Widget::subClickSlot_B(QString st)
{
    //完成对数据的添加
    ui->BPoint_text->setText(st);
    //解决的内容
    /*
     * 1.判断“图上距离”和“测量距离”的框是否为空
     *  1.1 如果为空，那么就使用比例尺上的比例
     *  1.2 如果不为空，那么就使用 比例=“图上距离”/“测量距离”得到的值进行计算
     *
     * 2.计算得到的L Lx Ly
    */

    //判断比例尺，如果 图上距离 和 测量距离 是变化的，那么就会调用下面函数
    //改变比例尺
    Scale_number();

    //获得比例尺上的数值
    double scale=ui->ScreenScale->value();

    //获得坐标值
    QVector<QPoint> point_ab = valueOfcord();
    //得到两个点之间计算得到的数值
    QPoint x1=point_ab[0];
    QPoint x2=point_ab[1];

    //计算Lx方向距离
    double Lx=qAbs(x1.x()-x2.x())*scale;
    QString ssx=QString::number(Lx);
    ui->LxDistance->setText(ssx);

    //计算Ly方向的距离
    double Ly=qAbs(x1.y()-x2.y())*scale;
    QString ssy=QString::number(Ly);
    ui->LyDistance->setText(ssy);

    //计算总距离
    /*
    double L=qSqrt((x1.x()-x2.x())*(x1.x()-x2.x())+
                   (x1.y()-x2.y())*(x1.y()-x2.y()));
                   */
    double L=qSqrt(Lx*Lx+Ly*Ly);//这里面已经进行了缩放了
    QString ss=QString::number(L);
    ui->totalDistance->setText(ss);

    this->raise();


}

Widget::~Widget()
{
    delete ui;
}

//捕捉窗口关闭信息
void Widget::closeEvent( QCloseEvent *event )
{
    //event->accept();
    DrawAPointtoBPoint->close();
    delete DrawAPointtoBPoint;

}



void Widget::on_DrawingClicked_clicked()
{
    /*
     * @Author:涛
     * @Time:2019-04-25 PM 21：13
     * @Place:435
     * @功能：
     * 当点击窗口时候：
     * 绘制一个窗口专门用于做图使用，
     * 满足窗口存在一定透明度;
     * 窗口需要覆盖整个桌面，但是可以看到后面的图标等信息;
     * 同时第一个窗口需要隐藏起来;
     *
     * 点击鼠标，此时出现一个点，
     * 拖动鼠标会有线段出现，
     * 当到达了指定的位置再次释放鼠标的时候，
     * 直线将会被绘制出来;
     * 同时三个距离信息会显示到方框中；
    */

    //完成绘图窗口的显示
    int desktop_width = QApplication::desktop()->width();
    int desktop_high = QApplication::desktop()->height();
    DrawAPointtoBPoint->resize (desktop_width, desktop_high);
    DrawAPointtoBPoint->setWindowFlags (Qt::FramelessWindowHint); // hide title pannel

    //设置窗口的透明度
    DrawAPointtoBPoint->setWindowOpacity(0.3);
    //显示绘图窗口
    DrawAPointtoBPoint->show();



}




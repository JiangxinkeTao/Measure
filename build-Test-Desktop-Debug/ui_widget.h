/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *totalDistance;
    QLabel *label_3;
    QTextEdit *APoint_text;
    QTextEdit *BPoint_text;
    QLabel *label_6;
    QTextEdit *LxDistance;
    QLabel *label_7;
    QTextEdit *LyDistance;
    QFrame *frame_2;
    QLabel *label_2;
    QDoubleSpinBox *ScreenScale;
    QPushButton *DrawingClicked;
    QLabel *label_8;
    QTextEdit *MapDistance;
    QLabel *label_9;
    QTextEdit *MeasureDistance;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(277, 457);
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 230, 261, 231));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 50, 61, 31));
        QFont font;
        font.setPointSize(12);
        label_4->setFont(font);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 130, 71, 31));
        label_5->setFont(font);
        totalDistance = new QTextEdit(frame);
        totalDistance->setObjectName(QString::fromUtf8("totalDistance"));
        totalDistance->setGeometry(QRect(120, 90, 104, 31));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 10, 61, 31));
        label_3->setFont(font);
        APoint_text = new QTextEdit(frame);
        APoint_text->setObjectName(QString::fromUtf8("APoint_text"));
        APoint_text->setGeometry(QRect(120, 10, 104, 31));
        BPoint_text = new QTextEdit(frame);
        BPoint_text->setObjectName(QString::fromUtf8("BPoint_text"));
        BPoint_text->setGeometry(QRect(120, 50, 104, 31));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 90, 71, 31));
        label_6->setFont(font);
        LxDistance = new QTextEdit(frame);
        LxDistance->setObjectName(QString::fromUtf8("LxDistance"));
        LxDistance->setGeometry(QRect(120, 130, 104, 31));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 170, 71, 31));
        label_7->setFont(font);
        LyDistance = new QTextEdit(frame);
        LyDistance->setObjectName(QString::fromUtf8("LyDistance"));
        LyDistance->setGeometry(QRect(120, 170, 104, 31));
        frame_2 = new QFrame(Widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setEnabled(true);
        frame_2->setGeometry(QRect(10, 0, 261, 221));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 130, 64, 25));
        label_2->setFont(font);
        ScreenScale = new QDoubleSpinBox(frame_2);
        ScreenScale->setObjectName(QString::fromUtf8("ScreenScale"));
        ScreenScale->setGeometry(QRect(180, 130, 61, 31));
        ScreenScale->setSingleStep(0.1);
        ScreenScale->setValue(1);
        DrawingClicked = new QPushButton(frame_2);
        DrawingClicked->setObjectName(QString::fromUtf8("DrawingClicked"));
        DrawingClicked->setGeometry(QRect(80, 170, 80, 33));
        DrawingClicked->setFont(font);
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 50, 64, 25));
        label_8->setFont(font);
        MapDistance = new QTextEdit(frame_2);
        MapDistance->setObjectName(QString::fromUtf8("MapDistance"));
        MapDistance->setEnabled(true);
        MapDistance->setGeometry(QRect(180, 50, 61, 31));
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 90, 64, 25));
        label_9->setFont(font);
        MeasureDistance = new QTextEdit(frame_2);
        MeasureDistance->setObjectName(QString::fromUtf8("MeasureDistance"));
        MeasureDistance->setGeometry(QRect(180, 90, 61, 31));
        layoutWidget = new QWidget(frame_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 215, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\346\265\213\350\267\235\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "\347\202\271B\345\235\220\346\240\207", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "X\350\275\264\345\220\221\350\267\235\347\246\273", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "\347\202\271A\345\235\220\346\240\207", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "\346\200\273\351\225\277\350\267\235\347\246\273L", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Widget", "Y\350\275\264\345\220\221\350\267\235\347\246\273", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "\345\261\217\345\271\225\346\257\224\344\276\213", 0, QApplication::UnicodeUTF8));
        DrawingClicked->setText(QApplication::translate("Widget", "\347\202\271\345\207\273\347\273\230\345\233\276", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Widget", "\345\233\276\344\270\212\350\267\235\347\246\273", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Widget", "\346\265\213\351\207\217\350\267\235\347\246\273", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\346\265\213\350\267\235\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

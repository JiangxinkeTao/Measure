/********************************************************************************
** Form generated from reading UI file 'drawingdistance.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWINGDISTANCE_H
#define UI_DRAWINGDISTANCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawingDistance
{
public:

    void setupUi(QWidget *DrawingDistance)
    {
        if (DrawingDistance->objectName().isEmpty())
            DrawingDistance->setObjectName(QString::fromUtf8("DrawingDistance"));
        DrawingDistance->resize(400, 300);

        retranslateUi(DrawingDistance);

        QMetaObject::connectSlotsByName(DrawingDistance);
    } // setupUi

    void retranslateUi(QWidget *DrawingDistance)
    {
        DrawingDistance->setWindowTitle(QApplication::translate("DrawingDistance", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DrawingDistance: public Ui_DrawingDistance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWINGDISTANCE_H

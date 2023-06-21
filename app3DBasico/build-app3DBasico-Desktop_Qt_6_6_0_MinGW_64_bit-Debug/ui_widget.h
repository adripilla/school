/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QDial *dial;
    QDial *dial_2;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(700, 500);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);"));
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(500, 0, 200, 500));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(126, 126, 94);"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 49, 16));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 10, 49, 16));
        dial = new QDial(widget);
        dial->setObjectName("dial");
        dial->setGeometry(QRect(20, 30, 50, 64));
        dial->setMaximum(360);
        dial_2 = new QDial(widget);
        dial_2->setObjectName("dial_2");
        dial_2->setGeometry(QRect(110, 30, 50, 64));
        dial_2->setMaximum(360);
        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(20, 90, 64, 23));
        lcdNumber_2 = new QLCDNumber(widget);
        lcdNumber_2->setObjectName("lcdNumber_2");
        lcdNumber_2->setGeometry(QRect(110, 90, 64, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "3D", nullptr));
        label->setText(QCoreApplication::translate("Widget", "ALFA", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "PHI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

#ifndef MY_QLABEL_H
#define MY_QLABEL_H

#include <QLabel>
#include <QMouseEvent>

class my_qlabel : public QLabel
{
    Q_OBJECT
public:
    explicit my_qlabel(QWidget *parent=0);
    //my_qlabel();
    void mousePressEvent(QMouseEvent *ev);

signals:
    void MOUSE_Pressed();
};

#endif // MY_QLABEL_H

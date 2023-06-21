#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>
#include "mapeo.h"
#include "matrix.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *event);
    void asignarFigura();
   // void dibujarFiguraOrientacionNormal();
    void dibujarFiguraMapeada(int);
    void keyPressEvent(QKeyEvent *event);
     void rotar(float angulo);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    QPainter *canvas;
    float Fig[69][3];
    float FigAux[69][3];

    int posxG;
    int ancho;
    int centroX, centroY;
    bool dibujoOrientacionNormal;
    bool dibujoMapeado;

    QTimer *time;
    int li,ls,X,Y,X2,Y2,X3,Y3,li2,ls2;
    bool gano;
    bool band,band2;
    QTimer*timer1;
};
#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>
#include <QKeyEvent>

#include "mapeo.h"

//MACRO DE C
#define radianes(grados)((double)(grados)* M_PI/180.0 )

struct Puntos3D
{
  int x,y,z;
  bool opcion; // 0 PARA MOVE, 1 PARA LINE

};


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *evt);
    void asignarCubo();
    void proyeccionCubo();
    void dibujarCubo();
    void inicializarPuerto();
    void lineto3D(int x, int y, int z, float alpha, float phi, int i);
    void moveto3D(int x, int y, int z, float alpha, float phi, int i);

    void escalacion(int xc,int yc, int zc,double fescx,double fescy, double fescz);
    void rotacionZ();

    void keyPressEvent(QKeyEvent *event);


private slots:
    void on_dial_sliderMoved(int position);

    void on_dial_2_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QPainter *canvas;
    QPointF points[16];
    Puntos3D *cubo;
    Mapeo mapeo1;
    int L, M;
    int ancho;
    float alpha, phi;
    //TRASLACION
    int Tx, Ty, Tz;
    //Escalacion
    double fescx, fescy, fescz;
    int xc, yc, zc;

    //Rotacion
    bool rx, ry, rz;
    int cX, cY, cZ;
    float anguloX, anguloY, anguloZ;

};
#endif // WIDGET_H

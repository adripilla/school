#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QtGui>
#include "mapeo.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void asignarFigura();
   // void dibujarFiguraOrientacionNormal();
    void dibujarFiguraMapeada(int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QPainter *canvas;
    float Fig[69][3];
    float FigAux[69][3];

    int ancho;
    int centroX, centroY;
    bool dibujoOrientacionNormal;
    bool dibujoMapeado;

    QTimer *time;
    int li,ls,X,Y;
    bool band;
    QTimer*timer1;
};
#endif // MAINWINDOW_H

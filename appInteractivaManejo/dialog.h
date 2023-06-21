#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QFileDialog>
#include <QImage>
#include <QTimer>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QImage EscanearImagen(const QImage &archEntrada, int,int, int,int);
    QImage EscanearImagen2(const QImage &archEntrada, int,int, int,int);
    QImage EscanearImagen3(const QImage &archEntrada, int,int, int,int);
    QImage EscanearImagen4(const QImage &archEntrada, int,int, int,int);
    QImage EscanearImagen5(const QImage &archEntrada, int,int, int,int);
    QImage EscanearImagen6(const QImage &archEntrada, int,int, int,int);

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_horizontalSlider_3_valueChanged(int value);

    void on_horizontalSlider_4_valueChanged(int value);

private:
    Ui::Dialog *ui;
    QString nomarch;
};
#endif // DIALOG_H

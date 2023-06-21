#include "dialog.h"
#include "ui_dialog.h"
#include <QMouseEvent>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    nomarch = "";
}

Dialog::~Dialog()
{
    delete ui;

}


QImage imagenOriginal;
QImage imagenEditada;
int accion = 0;
void Dialog::on_pushButton_8_clicked()
{
    QFileDialog dialogo(this);
    dialogo.setNameFilter("Imagenes(*.png *.bmp *.jpg *.jpeg *.gif)");
    dialogo.setViewMode(QFileDialog::Detail);
    nomarch = QFileDialog::getOpenFileName(this, "Abrir imagenes","C:\\Users\\123\\Desktop\\");
    if(!nomarch.isEmpty())
    {
    imagenOriginal= QImage(nomarch);
    imagenEditada = imagenEditada;
    QImage imagen(nomarch);
    ui->label->setPixmap(QPixmap::fromImage(imagen));
    ui->label->setScaledContents(true);
    ui->horizontalSlider->setMaximum(imagenOriginal.width());
    ui->horizontalSlider_2->setMaximum(imagenOriginal.width());
    ui->horizontalSlider_3->setMaximum(imagenOriginal.height());
    ui->horizontalSlider_4->setMaximum(imagenOriginal.height());
    }
    ui->label->setPixmap(QPixmap::fromImage(imagenOriginal));
    imagenEditada = imagenOriginal;
    ui->label->setScaledContents(true);
}


void Dialog::on_pushButton_7_clicked()
{
    ui->label->setPixmap(QPixmap::fromImage(imagenOriginal));
    imagenEditada = imagenOriginal;
    ui->label->setScaledContents(true);

}

void Dialog::on_pushButton_clicked()
{
    ui->label_2->setPixmap(QPixmap::fromImage( EscanearImagen(imagenOriginal,0,0,0,0)));
    accion = 1;
}


QImage Dialog::EscanearImagen(const QImage &archEntrada,int izq,int der, int sup,int inf)
{
    QImage archSalida(archEntrada.size(),archEntrada.format());
    for (int ren = 0; ren < archEntrada.height(); ren ++)
    {
     const   QRgb *pixelEntrada = reinterpret_cast<const QRgb*> (archEntrada.scanLine(ren));
     QRgb *pixelSalida = reinterpret_cast < QRgb*> (archSalida.scanLine(ren));
     for (int col= 0; col < archEntrada.width(); col ++ )
     {
         int rojo = qRed(pixelEntrada[col]);
         int verde = qGreen(pixelEntrada[col]);
         int azul = qBlue(pixelEntrada[col]);
         int alpha = qAlpha(pixelEntrada[col]);
         if(izq == 0 and der == 0)
             pixelSalida[col] = qRgba(rojo<<1, verde<<1, azul<<1,alpha);
         else{
             if(col > izq  and col < der and ren > sup and ren < inf)
                 pixelSalida[col] = qRgba(rojo<<1, verde<<1, azul<<1,alpha);
             else
                 pixelSalida[col] = qRgba(rojo, verde, azul,alpha);
         }


      }

    }
    return archSalida;
}

QImage Dialog::EscanearImagen2(const QImage &archEntrada, int izq, int der, int sup,int inf)
{
    QImage archSalida(archEntrada.size(),archEntrada.format());
    for (int ren = 0; ren < archEntrada.height(); ren ++)
    {
     const   QRgb *pixelEntrada = reinterpret_cast<const QRgb*> (archEntrada.scanLine(ren));
     QRgb *pixelSalida = reinterpret_cast < QRgb*> (archSalida.scanLine(ren));
     for (int col= 0; col < archEntrada.width(); col ++ )
     {
         int rojo = qRed(pixelEntrada[col]);
         int verde = qGreen(pixelEntrada[col]);
         int azul = qBlue(pixelEntrada[col]);
         int alpha = qAlpha(pixelEntrada[col]);
         if(izq == 0 and der == 0)
             pixelSalida[col] = qRgba(rojo>>1, verde>>1, azul>>1,alpha);
         else{
             if(col > izq  and col < der and ren > sup and ren < inf)
                 pixelSalida[col] = qRgba(rojo>>1, verde>>1, azul>>1,alpha);
             else
                 pixelSalida[col] = qRgba(rojo, verde, azul,alpha);
         }
      }
    }
    return archSalida;
}

QImage Dialog::EscanearImagen3(const QImage &archEntrada,int izq, int der, int sup,int inf)
{
    QImage archSalida(archEntrada.size(),archEntrada.format());
    for (int ren = 0; ren < archEntrada.height(); ren ++)
    {
     const   QRgb *pixelEntrada = reinterpret_cast<const QRgb*> (archEntrada.scanLine(ren));
     QRgb *pixelSalida = reinterpret_cast < QRgb*> (archSalida.scanLine(ren));
     for (int col= 0; col < archEntrada.width(); col ++ )
     {
         int rojo = qRed(pixelEntrada[col]);
         int verde = qGreen(pixelEntrada[col]);
         int azul = qBlue(pixelEntrada[col]);
         int alpha = qAlpha(pixelEntrada[col]);
         if(izq == 0 and der == 0)
             pixelSalida[col] = qRgba(rojo|verde, verde|azul, azul|rojo,alpha);
         else{
             if(col > izq  and col < der and ren > sup and ren < inf)
                 pixelSalida[col] = qRgba(rojo|verde, verde|azul, azul|rojo,alpha);
             else
                 pixelSalida[col] = qRgba(rojo, verde, azul,alpha);
         }
      }
    }
    return archSalida;
}

QImage Dialog::EscanearImagen4(const QImage &archEntrada, int izq, int der, int sup,int inf)
{
    QImage archSalida(archEntrada.size(),archEntrada.format());
    for (int ren = 0; ren < archEntrada.height(); ren ++)
    {
     const   QRgb *pixelEntrada = reinterpret_cast<const QRgb*> (archEntrada.scanLine(ren));
     QRgb *pixelSalida = reinterpret_cast < QRgb*> (archSalida.scanLine(ren));
     for (int col= 0; col < archEntrada.width(); col ++ )
     {
         int rojo = qRed(pixelEntrada[col]);
         int verde = qGreen(pixelEntrada[col]);
         int azul = qBlue(pixelEntrada[col]);
         int alpha = qAlpha(pixelEntrada[col]);
         if(izq == 0 and der == 0)
             pixelSalida[col] = qRgba(rojo&verde, verde&azul, azul&rojo,alpha);
         else{
             if(col > izq  and col < der and ren > sup and ren < inf)
                 pixelSalida[col] = qRgba(rojo&verde, verde&azul, azul&rojo,alpha);
             else
                 pixelSalida[col] = qRgba(rojo, verde, azul,alpha);
         }
      }
    }
    return archSalida;
}

QImage Dialog::EscanearImagen5(const QImage &archEntrada, int izq, int der, int sup,int inf)
{
    QImage archSalida(archEntrada.size(),archEntrada.format());
    for (int ren = 0; ren < archEntrada.height(); ren ++)
    {
     const   QRgb *pixelEntrada = reinterpret_cast<const QRgb*> (archEntrada.scanLine(ren));
     QRgb *pixelSalida = reinterpret_cast < QRgb*> (archSalida.scanLine(ren));
     for (int col= 0; col < archEntrada.width(); col ++ )
     {
         int rojo = qRed(pixelEntrada[col]);
         int verde = qGreen(pixelEntrada[col]);
         int azul = qBlue(pixelEntrada[col]);
         int alpha = qAlpha(pixelEntrada[col]);
         if(izq == 0 and der == 0)
             pixelSalida[col] = qRgba(rojo^verde, verde^azul, azul^rojo,alpha);
         else{
             if(col > izq  and col < der and ren > sup and ren < inf)
                 pixelSalida[col] = qRgba(rojo^verde, verde^azul, azul^rojo,alpha);
             else
                 pixelSalida[col] = qRgba(rojo, verde, azul,alpha);
         }
      }
    }
    return archSalida;
}

QImage Dialog::EscanearImagen6(const QImage &archEntrada, int izq, int der, int sup,int inf)
{
    QImage archSalida(archEntrada.size(),archEntrada.format());
    for (int ren = 0; ren < archEntrada.height(); ren ++)
    {
     const   QRgb *pixelEntrada = reinterpret_cast<const QRgb*> (archEntrada.scanLine(ren));
     QRgb *pixelSalida = reinterpret_cast < QRgb*> (archSalida.scanLine(ren));
     for (int col= 0; col < archEntrada.width(); col ++ )
     {
         int rojo = qRed(pixelEntrada[col]);
         int verde = qGreen(pixelEntrada[col]);
         int azul = qBlue(pixelEntrada[col]);
         int alpha = qAlpha(pixelEntrada[col]);
         if(izq == 0 and der == 0)
             pixelSalida[col] = qRgba(~rojo, ~verde, ~azul,alpha);
         else{
             if(col > izq  and col < der and ren > sup and ren < inf)
                 pixelSalida[col] = qRgba(~rojo, ~verde, ~azul,alpha);
             else
                 pixelSalida[col] = qRgba(rojo, verde, azul,alpha);
         }
      }
    }
    return archSalida;
}

void Dialog::on_pushButton_9_clicked()
{
    if(accion == 1)
        imagenEditada = EscanearImagen(imagenEditada,
                                       ui->horizontalSlider->value(),
                                       ui->horizontalSlider_2->value(),
                                       ui->horizontalSlider_3->value(),
                                       ui->horizontalSlider_4->value());
    if(accion == 2)
        imagenEditada = EscanearImagen2(imagenEditada,ui->horizontalSlider->value(),ui->horizontalSlider_2->value(),ui->horizontalSlider_3->value(),ui->horizontalSlider_4->value());
    if(accion == 3)
        imagenEditada = EscanearImagen3(imagenEditada,ui->horizontalSlider->value(),ui->horizontalSlider_2->value(),ui->horizontalSlider_3->value(),ui->horizontalSlider_4->value());
    if(accion == 4)
        imagenEditada = EscanearImagen4(imagenEditada,ui->horizontalSlider->value(),ui->horizontalSlider_2->value(),ui->horizontalSlider_3->value(),ui->horizontalSlider_4->value());
    if(accion == 5)
        imagenEditada = EscanearImagen5(imagenEditada,ui->horizontalSlider->value(),ui->horizontalSlider_2->value(),ui->horizontalSlider_3->value(),ui->horizontalSlider_4->value());
    if(accion == 6)
        imagenEditada = EscanearImagen6(imagenEditada,ui->horizontalSlider->value(),ui->horizontalSlider_2->value(),ui->horizontalSlider_3->value(),ui->horizontalSlider_4->value());
    ui->label->setPixmap(QPixmap::fromImage(imagenEditada));
}


void Dialog::on_horizontalSlider_valueChanged(int value)
{
    ui->label_3->setText("lim.izquierdo "+QString::number(value));
}


void Dialog::on_horizontalSlider_2_valueChanged(int value)
{
    ui->label_4->setText("lim.derecho "+QString::number(value));
}


void Dialog::on_pushButton_2_clicked()
{
    ui->label_2->setPixmap(QPixmap::fromImage( EscanearImagen2(imagenOriginal,0,0,0,0)));
    accion = 2;
}


void Dialog::on_pushButton_3_clicked()
{
    ui->label_2->setPixmap(QPixmap::fromImage( EscanearImagen3(imagenOriginal,0,0,0,0)));
    accion = 3;
}


void Dialog::on_pushButton_4_clicked()
{
    ui->label_2->setPixmap(QPixmap::fromImage( EscanearImagen4(imagenOriginal,0,0,0,0)));
    accion = 4;
}


void Dialog::on_pushButton_5_clicked()
{
    ui->label_2->setPixmap(QPixmap::fromImage( EscanearImagen5(imagenOriginal,0,0,0,0)));
    accion = 5;
}


void Dialog::on_pushButton_6_clicked()
{
    ui->label_2->setPixmap(QPixmap::fromImage( EscanearImagen6(imagenOriginal,0,0,0,0)));
    accion = 6;
}


void Dialog::on_horizontalSlider_3_valueChanged(int value)
{
     ui->label_6->setText("lim.superior "+QString::number(value));
}


void Dialog::on_horizontalSlider_4_valueChanged(int value)
{
     ui->label_5->setText("lim.inferior "+QString::number(value));
}


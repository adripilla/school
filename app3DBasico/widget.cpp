#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    alpha = 63.4F;
    phi = 30.0F;

    Tx=Ty=Tz=0;
    //Rotacion
    xc = 150;
    yc = 100;
    zc = 50;
    fescx = fescy  = fescz= 0;

    rx = ry = rz = false;
    anguloX = anguloY = anguloZ = 0;
    cX = 150;
    cY = 100;
    cZ = 50;

    asignarCubo();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *evt)
{
    Q_UNUSED(evt)

    inicializarPuerto();
    proyeccionCubo();
}

void Widget::asignarCubo()
{
    Puntos3D cuboBase[]={{100,50,0,0},{200,50,0,1},{200,150,0,1},
                         {100,150,0,1},{100,50,0,1},{100,50,100,1},
                         {200,50,100,1},{200,150,100,1},{200,150,0,1},
                         {200,50,0,0},{200,50,100,1},{100,50,100,0},
                         {100,150,100,1},{100,150,0,1},{100,150,100,0},
                         {200,150,100,1}};

    cubo = new Puntos3D[16];
    for(int i =0; i <16; i++)
        cubo[i]=cuboBase[i];
    //  /
    inicializarPuerto();//?

    ancho = this->size().width() - ui->widget->size().width();


}

void Widget::proyeccionCubo()
{
    canvas = new QPainter(this);
    canvas->setPen(QPen(Qt::black));
    canvas->drawLine(0, size().height()-1, ancho, size().height());
    canvas->drawLine(1,1,1,size().height());

    //DIBUJAR EL EJE Z
    float zx1 = 0;
    float zy1 = 0;
    float zx2 = ancho * cos(radianes(phi));
    float zy2 = ancho * sin(qDegreesToRadians(phi));

    // MAPEAR LOS VALORES PARA DIBUJAR EL EJE Z
    int x1, y1, x2, y2;
    mapeo1.mapear(&zx1, &zy1,&x1,y1,L,M);
    mapeo1.mapear(&zx2, &zy2,&x2,y2,L,M);

    canvas->drawLine(x1,y1,x2,y2);

    // DIBUJAR CUBO + TRASLACION

    /*
    for(int i =0; i < 16; i++)
    {


        float fz = cubo[i].z;
        float fx = cubo[i].x;
        float fy = cubo[i].y;

        if(rz)
        {
         fz = cubo[i].z;
         fx = floor((cubo[i].x - cX) * cos(radianes(anguloZ)) - (cubo[i].y - cY) * sin(radianes(anguloZ) + 0.5));
         fy = floor((cubo[i].x - cX) * sin(radianes(anguloZ)) + (cubo[i].y - cY) * cos(radianes(anguloZ) + 0.5));
        }

        if(cubo[i].opcion)
            lineto3D(cubo[i].x + Tx, cubo[i].y + Ty, cubo[i].z + Tz, radianes(alpha), qDegreesToRadians(phi),i);
        else
            moveto3D(cubo[i].x + Tx, cubo[i].x + Ty, cubo[i].z + Tz, radianes(alpha), qDegreesToRadians(phi),i);
    }
    canvas->setPen(QPen(QColor(255,100,0),3));
    dibujarCubo();
    canvas->end();
    */

    //DIBUJAR + ESCALACION

    /*
    for(int i = 0; i < 16; i++)
    {
        int rx = xc + ((cubo[i].x - xc)*fescx);
        int ry = yc + ((cubo[i].y - yc)*fescy);
        int rz = zc + ((cubo[i].z - zc)*fescz);

        if(cubo[i].opcion)
            lineto3D(rx+Tx, ry+Ty, rz+Tz, radianes(alpha), qDegreesToRadians(phi),i);
        else
            moveto3D(rx+Tx, ry+Ty, rz+Tz, radianes(alpha), qDegreesToRadians(phi),i);
    }

    canvas->setPen(QPen(QColor(255,100,0),3));
    proyeccionCubo();
    canvas->end();
    */


    //DIBUJAR CUBO + ROTACION

    float fx,fy,fz;
    for(int i =0; i < 16; i++)
    {


         fz = cubo[i].z;
         fx = cubo[i].x;
         fy = cubo[i].y;

         if(rz)
        {
            fz = cubo[i].z;
            fx = floor((cubo[i].x - cX) * cos(radianes(anguloZ)) - (cubo[i].y - cY) * sin(radianes(anguloZ) )+ 0.5);
            fy = floor((cubo[i].x - cX) * sin(radianes(anguloZ)) + (cubo[i].y - cY) * cos(radianes(anguloZ) )+ 0.5);
        }

        if(rx)
        {
            fz = floor((cubo[i]. y- cY) * cos(radianes(anguloX)) - (cubo[i].z - cZ) * sin(radianes(anguloX) )+ 0.5);
            fx = cubo[i].x;
            fy = floor((cubo[i].y - cY) * sin(radianes(anguloX)) + (cubo[i].z - cZ) * cos(radianes(anguloX) )+ 0.5);
        }
        if(ry)
        {
            fz = floor((cubo[i].x - cX) * cos(radianes(anguloY)) - (cubo[i].z - cZ) * sin(radianes(anguloY) )+ 0.5);
            fx = floor((cubo[i].x - cX) * sin(radianes(anguloY)) + (cubo[i].z - cZ) * cos(radianes(anguloY) )+ 0.5);
            fy = cubo[i].y;
        }

        if(cubo[i].opcion)
            lineto3D(fx+Tx, fy+Ty, fz+Tz, radianes(alpha), qDegreesToRadians(phi),i);
        else
            moveto3D(fx+Tx, fy+Ty, fz+Tz, radianes(alpha), qDegreesToRadians(phi),i);
    }
    canvas->setPen(QPen(QColor(255,100,0),3));
    dibujarCubo();
    canvas->end();




}

void Widget::dibujarCubo()
{
    for(int i = 0; i <15; i++)
        canvas->drawLine(points[i].x(), points[i].y(), points[i+1].x(), points[i+1].y());
}

void Widget::inicializarPuerto()
{
    mapeo1.ventana(0,0,ancho, size().height());
    mapeo1.puerto(0,0,ancho, size().height());
    L = 0;
    M = size().height();

}

void Widget::lineto3D(int x, int y, int z, float alpha, float phi, int i)
{
    float xp, yp;
    int longitud; // SERIA L
    float tanalpha;
    if( (tanalpha = tan(alpha)) != 0)
        longitud = int(z/tanalpha); // EVITAR DIVIDIR ENTRE 0
    else
        longitud = 0;

    xp = x + longitud * cos(phi);
    yp = y + longitud * cos(phi);

    int x1, y1;
    mapeo1.mapear(&xp, &yp, &x1, y1, L,M);
    points[i].setX(x1);
    points[i].setY(y1);



}

void Widget::moveto3D(int x, int y, int z, float alpha, float phi, int i)
{
    float xp, yp;
    int longitud; // SERIA L
    float tanalpha;
    if( (tanalpha = tan(alpha)) != 0)
        longitud = int(z/tanalpha); // EVITAR DIVIDIR ENTRE 0
    else
        longitud = 0;

    xp = x + longitud * cos(phi);
    yp = y + longitud * cos(phi);

    int x1, y1;
    mapeo1.mapear(&xp, &yp, &x1, y1, L,M);
    points[i].setX(x1);
    points[i].setY(y1);
}
void Widget::escalacion(int xc,int yc, int zc,double fescx,double fescy, double fescz)
{
    for(int i = 0; i < 16; i++)
    {

        cubo[i].x =xc + ( ( cubo[i].x - xc) * fescx );
        cubo[i].y =yc + ( ( cubo[i].y - yc) * fescy );
        cubo[i].z =zc + ( ( cubo[i].z - zc) * fescz );


        /*
        int rx = xc + ((cubo[i].x - xc)*fescx);
        int ry = yc + ((cubo[i].y - yc)*fescy);
        int rz = zc + ((cubo[i].z - zc)*fescz);

        if(cubo[i].opcion)
            lineto3D(rx+Tx, ry+Ty, rz+Tz, radianes(alpha), qDegreesToRadians(phi),i);
        else
            moveto3D(rx+Tx, ry+Ty, rz+Tz, radianes(alpha), qDegreesToRadians(phi),i);
        */
    }
    /*
    canvas->setPen(QPen(QColor(255,100,0),3));
    proyeccionCubo();
    canvas->end();
    */

    dibujarCubo();
    update();
}

void Widget::rotacionZ()
{

}


void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_D)
        Tx+=5;
    if(event->key()==Qt::Key_A)
        Tx-=5;
    if(event->key()==Qt::Key_W)
        Ty+=5;
    if(event->key()==Qt::Key_S)
        Ty-=5;

    //ESCALACION
    //EJE DE X TECLAS R & T
    if(event->key()==Qt::Key_R)
    {
        float x,y,z;
        x = 0.9;
        y = 1;
        z = 1;
        escalacion(150,100,50,x,y,z);
    }
    if(event->key()==Qt::Key_T)
    {
        float x,y,z;
        x = 1.1;
        y = 1;
        z = 1;
        escalacion(150,100,50,x,y,z);
    }
    //EJE Y TECLAS F & G
    if(event->key()==Qt::Key_F)
    {
        float x,y,z;
        x = 1;
        y = 0.9;
        z = 1;
        escalacion(150,100,50,x,y,z);
    }

    if(event->key()==Qt::Key_G)
    {
        float x,y,z;
        x = 1;
        y = 1.1;
        z = 1;
        escalacion(150,100,50,x,y,z);
    }

    //EJE DE Z TECLAS C & V
    if(event->key()==Qt::Key_C)
    {
        float x,y,z;
        x = 1;
        y = 1;
        z = 0.9;
        escalacion(150,100,50,x,y,z);
    }

    if(event->key()==Qt::Key_V)
    {
        float x,y,z;
        x = 1;
        y = 1;
        z = 1.1;
        escalacion(150,100,50,x,y,z);
    }


    //Rotacion
    if(event->key()==Qt::Key_O)
    {
        anguloZ -=5;
        rz = true;
        rx = false;
        ry = false;
    }
    if(event->key()==Qt::Key_P){
        anguloZ += 5;
        rz = true;
        rx = false;
        ry = false;
    }

    if(event->key()==Qt::Key_K)
    {
        anguloX -=5;
        rx = true;
        ry = false;
        rz = false;
    }
    if(event->key()==Qt::Key_L)
    {
        anguloX += 5;
        rx = true;
        ry = false;
        rz = false;
    }

    if(event->key()==Qt::Key_N)
    {
        anguloY -=5;
        ry = true;
        rz = false;
        rx = false;
    }
    if(event->key()==Qt::Key_M)
    {
        anguloY += 5;
        ry = true;
        rz = false;
        rx = false;
    }


    update();
}


void Widget::on_dial_sliderMoved(int position)
{
    alpha=position;
    ui->lcdNumber->display(position);
    inicializarPuerto();
    update();
}


void Widget::on_dial_2_valueChanged(int value)
{
    phi=value;
    ui->lcdNumber_2->display(value);
    inicializarPuerto();
    update();
}


void Widget::on_pushButton_clicked()
{
    escalacion(150,100, 50, ui->doubleSpinBox->value(),ui->doubleSpinBox_2->value(), ui->doubleSpinBox_3->value());
    //escalacion(150,100, fescx, fescy);
    //proyeccionCubo();
}


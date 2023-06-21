#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dibujoMapeado = true;
    timer1 = new QTimer();
    asignarFigura();
    connect(timer1,SIGNAL(timeout()),SLOT(repaint()));
    timer1->start(10);

    li =0,ls=320;
    X=370,Y=380;

    band = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    canvas = new QPainter(this);


          if(li <=ls){
                dibujarFiguraMapeada(li);
                li++;
            }
            else
                li=0;


    canvas->end();
}

void MainWindow::asignarFigura()
{
    Fig[0][0] = 0; Fig[0][1] = 0; Fig[0][2] = 1;
    Fig[1][0] = 0; Fig[1][1] = 10; Fig[0][2] = 1;
    Fig[2][0] = 15; Fig[2][1] = 10; Fig[0][2] = 1;
    Fig[3][0] = 15; Fig[3][1] = 0; Fig[0][2] = 1;
    Fig[4][0] = 15; Fig[4][1] = 20; Fig[0][2] = 1;
    Fig[5][0] = 25; Fig[5][1] = 20; Fig[0][2] = 1;
    Fig[6][0] = 25; Fig[6][1] = 0; Fig[0][2] = 1;
    Fig[7][0] = 25; Fig[7][1] = 10; Fig[0][2] = 1;
    Fig[8][0] = 40; Fig[8][1] = 10; Fig[0][2] = 1;
    Fig[9][0] = 40; Fig[9][1] = 0; Fig[0][2] = 1;
    Fig[10][0] = 40; Fig[10][1] = 20; Fig[0][2] = 1;
    Fig[11][0] = 45; Fig[11][1] = 25; Fig[0][2] = 1;
    Fig[12][0] = 50; Fig[12][1] = 20; Fig[0][2] = 1;
    Fig[13][0] = 50; Fig[13][1] = 0; Fig[0][2] = 1;
    Fig[14][0] = 50; Fig[14][1] = 10; Fig[0][2] = 1;
    Fig[15][0] = 60; Fig[15][1] = 10; Fig[0][2] = 1;
    Fig[16][0] = 60; Fig[16][1] = 0; Fig[0][2] = 1;
    Fig[17][0] = 60; Fig[17][1] = 20; Fig[0][2] = 1;
    Fig[18][0] = 70; Fig[18][1] = 20; Fig[0][2] = 1;
    Fig[19][0] = 70; Fig[19][1] = 0; Fig[0][2] = 1;
    Fig[20][0] = 70; Fig[20][1] = 30; Fig[0][2] = 1;
    Fig[21][0] = 85; Fig[21][1] = 30; Fig[0][2] = 1;
    Fig[22][0] = 85; Fig[22][1] = 0; Fig[0][2] = 1;

    Fig[23][0] = 0+85; Fig[23][1] = 0; Fig[0][2] = 1;
    Fig[24][0] = 0+85; Fig[24][1] = 10; Fig[0][2] = 1;
    Fig[25][0] = 15+85; Fig[25][1] = 10; Fig[0][2] = 1;
    Fig[26][0] = 15+85; Fig[26][1] = 0; Fig[0][2] = 1;
    Fig[27][0] = 15+85; Fig[27][1] = 20; Fig[0][2] = 1;
    Fig[28][0] = 25+85; Fig[28][1] = 20; Fig[0][2] = 1;
    Fig[29][0] = 25+85; Fig[29][1] = 0; Fig[0][2] = 1;
    Fig[30][0] = 25+85; Fig[30][1] = 10; Fig[0][2] = 1;
    Fig[31][0] = 40+85; Fig[31][1] = 10; Fig[0][2] = 1;
    Fig[32][0] = 40+85; Fig[32][1] = 0; Fig[0][2] = 1;
    Fig[33][0] = 40+85; Fig[33][1] = 20; Fig[0][2] = 1;
    Fig[34][0] = 45+85; Fig[34][1] = 25; Fig[0][2] = 1;
    Fig[35][0] = 50+85; Fig[35][1] = 20; Fig[0][2] = 1;
    Fig[36][0] = 50+85; Fig[36][1] = 0; Fig[0][2] = 1;
    Fig[37][0] = 50+85; Fig[37][1] = 10; Fig[0][2] = 1;
    Fig[38][0] = 60+85; Fig[38][1] = 10; Fig[0][2] = 1;
    Fig[39][0] = 60+85; Fig[39][1] = 0; Fig[0][2] = 1;
    Fig[40][0] = 60+85; Fig[40][1] = 20; Fig[0][2] = 1;
    Fig[41][0] = 70+85; Fig[41][1] = 20; Fig[0][2] = 1;
    Fig[42][0] = 70+85; Fig[42][1] = 0; Fig[0][2] = 1;
    Fig[43][0] = 70+85; Fig[43][1] = 30; Fig[0][2] = 1;
    Fig[44][0] = 85+85; Fig[44][1] = 30; Fig[0][2] = 1;
    Fig[45][0] = 85+85; Fig[45][1] = 0; Fig[0][2] = 1;

    Fig[46][0] = 0+85+85; Fig[46][1] = 0; Fig[0][2] = 1;
    Fig[47][0] = 0+85+85; Fig[47][1] = 10; Fig[0][2] = 1;
    Fig[48][0] = 15+85+85; Fig[48][1] = 10; Fig[0][2] = 1;
    Fig[49][0] = 15+85+85; Fig[49][1] = 0; Fig[0][2] = 1;
    Fig[50][0] = 15+85+85; Fig[50][1] = 20; Fig[0][2] = 1;
    Fig[51][0] = 25+85+85; Fig[51][1] = 20; Fig[0][2] = 1;
    Fig[52][0] = 25+85+85; Fig[52][1] = 0; Fig[0][2] = 1;
    Fig[53][0] = 25+85+85; Fig[53][1] = 10; Fig[0][2] = 1;
    Fig[54][0] = 40+85+85; Fig[54][1] = 10; Fig[0][2] = 1;
    Fig[55][0] = 40+85+85; Fig[55][1] = 0; Fig[0][2] = 1;
    Fig[56][0] = 40+85+85; Fig[56][1] = 20; Fig[0][2] = 1;
    Fig[57][0] = 45+85+85; Fig[57][1] = 25; Fig[0][2] = 1;
    Fig[58][0] = 50+85+85; Fig[58][1] = 20; Fig[0][2] = 1;
    Fig[59][0] = 50+85+85; Fig[59][1] = 0; Fig[0][2] = 1;
    Fig[60][0] = 50+85+85; Fig[60][1] = 10; Fig[0][2] = 1;
    Fig[61][0] = 60+85+85; Fig[61][1] = 10; Fig[0][2] = 1;
    Fig[62][0] = 60+85+85; Fig[62][1] = 0; Fig[0][2] = 1;
    Fig[63][0] = 60+85+85; Fig[63][1] = 20; Fig[0][2] = 1;
    Fig[64][0] = 70+85+85; Fig[64][1] = 20; Fig[0][2] = 1;
    Fig[65][0] = 70+85+85; Fig[65][1] = 0; Fig[0][2] = 1;
    Fig[66][0] = 70+85+85; Fig[66][1] = 30; Fig[0][2] = 1;
    Fig[67][0] = 85+85+85; Fig[67][1] = 30; Fig[0][2] = 1;
    Fig[68][0] = 85+85+85; Fig[68][1] = 0; Fig[0][2] = 1;
}

void MainWindow::dibujarFiguraMapeada(int resta)
{
    QPen pen(QColor(0,0,255),2);
    canvas->setPen(pen);
    //LINEA VERTICAL
    //canvas->drawLine(0,0,0,this->size().height());
    //LINEA HORIZONTAL
    //canvas->drawLine(0,this->size().height(),ancho,size().height());

    //EJES CARTESIANOS
    //canvas->drawLine(0,centroY,ancho,centroY);
    //canvas->drawLine(centroX, 0, centroX, size().height());

    Mapeo dibujo;

    //dibujo.ventana(0,0,ancho,this->size().height());
    //dibujo.puerto(0,0,ancho*2,this->size().height()*2);

    //EVALUACION
   // dibujo.ventana(0,0,10,10);
   // dibujo.puerto(0, 0, centroX, centroY);
   // canvas->drawRect(centroX, centroY, ancho, size().height());
   // int L = centroX;//centroX;
   // int M = size().height(); //size().height();

    //USANDO LAS DIMENSIONES DE UNA HOJA DE CUADERNO
    dibujo.ventana(0,0,100,50);

    dibujo.puerto(0,10,X,Y);
   // canvas->drawRect(150,100, 220, 280);
    int L= 0;
    //int M= size().height() - 22;
    int M= 480;

    canvas->setPen(QColor(0,0,0));

    //ESQ. SUPERIOR IZQ
    //int L = 0;
    //int M = this->size().height();

    //ORIGEN CARTESIANO
    //int L = centroX;
    //int M = centroY;

    int x1, y1, x2, y2;
    int xx=0;

    canvas->drawLine(0,400,X*2-100,400);
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 69; i++) {
            dibujo.mapear(&Fig[i][0],&Fig[i][1],&x1,y1,L,M);
            dibujo.mapear(&Fig[i+1][0]+xx,&Fig[i+1][1],&x2,y2,L,M);
            canvas->drawLine(x1-resta,y1-100,x2-resta,y2-100);
        }

    }
}




void MainWindow::on_pushButton_clicked()
{
    X-=10;
    Y-=10;
}


void MainWindow::on_pushButton_2_clicked()
{
    X+=10;
    Y+=10;
}


void MainWindow::on_pushButton_3_clicked()
{
    Y+=10;
}


void MainWindow::on_pushButton_4_clicked()
{
    Y-=10;
}


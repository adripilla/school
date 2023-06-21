#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    dibujoMapeado = true;
    timer1 = new QTimer();
    asignarFigura();
    connect(timer1,SIGNAL(timeout()),SLOT(repaint()));
    li =0,ls=280;
    li2 =0,ls2=200;
    X=300,Y=400;
    X2=50,Y2=50;
    X3=99,Y3=99;
    band = gano = band2 = false;
    posxG=230;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    canvas = new QPainter(this);

    canvas->setPen(Qt::white);
    canvas->setFont(QFont("Arial", 12));
    QString t = QString::number( li2);
    canvas->drawText(500, 100, t);


    //baja garra
    if(band && !gano){
        Fig[20][1]--;
        Fig[21][1]--;
        Fig[22][1]--;
        Fig[23][1]--;
        Fig[24][1]--;
        Fig[25][1]--;
        li++;
    }

    //sube agarrando
    if(!band && li > 1 && !gano){
        Fig[20][1]++;
        Fig[21][1]++;
        Fig[22][1]++;
        Fig[23][1]++;
        Fig[24][1]++;
        Fig[25][1]++;
        if(posxG >240 and posxG < 260 and li%2 ){
            Fig[26][1]++;
            Fig[27][1]++;
            Fig[28][1]++;
            Fig[29][1]++;
            Fig[30][1]++;
            Fig[31][1]++;
            Fig[32][1]++;
            Fig[33][1]++;
            Fig[34][1]++;
            Fig[35][1]++;
            Fig[36][1]++;
        }
        li--;
    }


    if(li==ls)
        band = false;
    if(li == 1){
        if(posxG >240 and posxG < 260){
            gano = true;
            band2 = true;
        }
        else
            timer1->stop();
        band = true;

    }


    //baja
    if(gano && band2){
        Fig[20][1]--;
        Fig[21][1]--;
        Fig[22][1]--;
        Fig[23][1]--;
        Fig[24][1]--;
        Fig[25][1]--;
        Fig[26][1]--;
        Fig[27][1]--;
        Fig[28][1]--;
        Fig[29][1]--;
        Fig[30][1]--;
        Fig[31][1]--;
        Fig[32][1]--;
        Fig[33][1]--;
        Fig[34][1]--;
        Fig[35][1]--;
        Fig[36][1]--;
        li2++;
        if(li2 == ls2){
            band2=false;
            gano = false;
            timer1->stop();
        }
    }
    dibujarFiguraMapeada(li);
    canvas->end();
}

void Widget::asignarFigura()
{

    Fig[0][0] = 0; Fig[0][1] = 0; Fig[0][2] = 1;
    Fig[1][0] = 0; Fig[1][1] = 429; Fig[0][2] = 1;
    Fig[2][0] = 50; Fig[2][1] = 495; Fig[0][2] = 1;
    Fig[3][0] = 50; Fig[3][1] = 0; Fig[0][2] = 1;
    Fig[4][0] = 325; Fig[4][1] = 0; Fig[0][2] = 1;
    Fig[5][0] = 325; Fig[5][1] = 495; Fig[0][2] = 1;
    Fig[6][0] = 50; Fig[6][1] = 495; Fig[0][2] = 1;
    Fig[7][0] = 50; Fig[7][1] = 420; Fig[0][2] = 1;
    Fig[8][0] = 325; Fig[8][1] = 420; Fig[0][2] = 1;
    Fig[9][0] = 325; Fig[9][1] = 200; Fig[0][2] = 1;
    Fig[10][0] = 50; Fig[10][1] = 200; Fig[0][2] = 1;
    Fig[11][0] = 50; Fig[11][1] = 155; Fig[0][2] = 1;
    Fig[12][0] = 75; Fig[12][1] = 180; Fig[0][2] = 1;
    Fig[13][0] = 50; Fig[13][1] = 200; Fig[0][2] = 1;
    Fig[14][0] = 325; Fig[14][1] = 200; Fig[0][2] = 1;
    Fig[15][0] = 350; Fig[15][1] = 180; Fig[0][2] = 1;
    Fig[16][0] = 325; Fig[16][1] = 150; Fig[0][2] = 1;
    Fig[17][0] = 350; Fig[17][1] = 180; Fig[0][2] = 1;
    Fig[18][0] = 75; Fig[18][1] = 180; Fig[0][2] = 1;


    Fig[19][0] = 50; Fig[19][1] = 100; Fig[19][2] = 1;
    Fig[20][0] = 50; Fig[20][1] = 50; Fig[20][2] = 1;
    Fig[21][0] = 0; Fig[21][1] = 0; Fig[21][2] = 1;
    Fig[22][0] = 50; Fig[22][1] = 50; Fig[22][2] = 1;
    Fig[23][0] = 50; Fig[23][1] = 0; Fig[23][2] = 1;
    Fig[24][0] = 50; Fig[24][1] = 50; Fig[24][2] = 1;
    Fig[25][0] = 100; Fig[25][1] = 0; Fig[25][2] = 1;

    Fig[26][0] = 0; Fig[26][1] = 40; Fig[26][2] = 1;
    Fig[27][0] = 10; Fig[27][1] = 45; Fig[27][2] = 1;
    Fig[28][0] = 20; Fig[28][1] = 45; Fig[28][2] = 1;
    Fig[29][0] = 25; Fig[29][1] = 40; Fig[29][2] = 1;
    Fig[30][0] = 30; Fig[30][1] = 45; Fig[30][2] = 1;
    Fig[31][0] = 40; Fig[31][1] = 45; Fig[31][2] = 1;
    Fig[32][0] = 50; Fig[32][1] = 40; Fig[32][2] = 1;
    Fig[33][0] = 50; Fig[33][1] = 30; Fig[33][2] = 1;
    Fig[34][0] = 25; Fig[34][1] = 0; Fig[34][2] = 1;
    Fig[35][0] = 0; Fig[35][1] = 30; Fig[35][2] = 1;
    Fig[36][0] = 0; Fig[36][1] = 40; Fig[36][2] = 1;


    for(int r = 0; r < 37; r++)
        for(int c = 0; c < 3; c++)
            FigAux[r][c] = Fig[r][c];


}

void Widget::dibujarFiguraMapeada(int ani)
{
    QPen pen(QColor(255,255,255),2);
    canvas->setPen(pen);
    Mapeo dibujo,garra,cubo;
    dibujo.ventana(0,0,500,500);
    garra.ventana(0,0,100,100);
    cubo.ventana(0,0,99,99);

    dibujo.puerto(0,10,X,Y);
    garra.puerto(0,10,X2,Y2);
    cubo.puerto(0,10,X3,Y3);

   // cubo.puerto(0,10,99,99);

    int L= 200;
    int M= 510;
    int L2= posxG;
    int M2= 230;
    int L3= 250;
    int M3= 400;

    canvas->setPen(QColor(255,255,255));

    int x1, y1, x2, y2;
    for (int i = 0; i < 18; i++) {
        dibujo.mapear(&Fig[i][0],&Fig[i][1],&x1,y1,L,M);
        dibujo.mapear(&Fig[i+1][0],&Fig[i+1][1],&x2,y2,L,M);
        canvas->drawLine(x1,y1-100,x2,y2-100);
    }
    for (int i = 19; i < 25; i++) {
        garra.mapear(&Fig[i][0],&Fig[i][1],&x1,y1,L2,M2);
        garra.mapear(&Fig[i+1][0],&Fig[i+1][1],&x2,y2,L2,M2);
        canvas->drawLine(x1,y1-100,x2,y2-100);
    }
    for (int i = 26; i < 36; i++) {
        cubo.mapear(&Fig[i][0],&Fig[i][1],&x1,y1,L3,M3);
        cubo.mapear(&Fig[i+1][0],&Fig[i+1][1],&x2,y2,L3,M3);
        canvas->drawLine(x1,y1-100,x2,y2-100);
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_D)
        posxG++;
    if(event->key() == Qt::Key_A)
        posxG--;
    if(event->key() == Qt::Key_S){
        band = true;
        timer1->start(10);
        li++;
    }

    update();

}


void Widget::on_pushButton_clicked()
{
    X+=10;
    Y+=10;
    X2+=10;
    Y2+=10;
    X3+=10;
    Y3+=10;
    ls+=15;
    ls2+=15;
    update();
}


void Widget::on_pushButton_2_clicked()
{
    X-=10;
    Y-=10;
    X2-=10;
    Y2-=10;
    X3-=10;
    Y3-=10;
    ls-=15;
    ls2-=15;
    update();
}


void Widget::on_pushButton_3_clicked()
{
    rotar(45);
}


void Widget::rotar(float angulo)
{
    Matrix fig,id,fres;
    fig.Inicializa(11,3);
    id.Inicializa(3,3);
    fres.Inicializa(11,3);

    for(int i=0; i<fig.numRen();i++)
        for(int j=0; j<fig.numCol();j++)
            fig.SET(i,j,Fig[i+26][j]);

    fres.rotacion(fig,id,angulo);

    for(int r=0; r<fres.numRen(); r++)
        for(int c=0; c<fres.numCol(); c++)
            Fig[r+26][c] = fres.GET(r,c);

    update();

}

void Widget::on_pushButton_4_clicked()
{
    timer1->stop();
    li =0,ls=280;
    li2 =0,ls2=200;
    X=300,Y=400;
    X2=50,Y2=50;
    X3=99,Y3=99;
    band = gano = band2 = false;
    posxG=230;
    for(int i=0; i<37;i++)
        for(int j=0; j<3;j++)
            Fig[i][j] = FigAux[i][j];
    update();
}


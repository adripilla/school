#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    timer1 = new QTimer();
    timer2 = new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(mover()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(meteoro()));
    timer1->start(10);
    timer2->start(20);
    ui->label_9->setGeometry(1800,10,ui->label_9->width(),ui->label_9->height());

}

void Dialog::paintEvent(QPaintEvent *evt){
    QPainter canvas(this);
    QPen blanco(QColor(255,255,255));
    blanco.setWidth(1);
    canvas.setPen(blanco);
    for(int i = 0 ; i< 1000; i++){
       int psx = QRandomGenerator::global()->bounded(0,1800);
       int psy = QRandomGenerator::global()->bounded(0,800);
       canvas.drawPoint(psx,psy);
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::mover()
{
    mercurio();
    venus();
    tierra();
    marte();
    jupiter();
    saturno();

}


void Dialog::mercurio()
{
    static int x = ui->label_2->x();
    static int y = ui->label_2->y();
    static bool banx = true;
    static bool bany = true;
    ui->label_3->setText("x:"+QString::number(x)+" y:"+QString::number(y));
    if(ui->label_2->x() == 1100)
        banx = false;
    if(ui->label_2->x() == 700)
        banx = true;
    if(banx){
        x++;
        if(ui->label_2->x() == 900)
            bany = false;
    }
    else{
        x--;
        if(ui->label_2->x() == 900)
            bany = true;
    }
    if(bany)
        y++;
    else
        y--;
    ui->label_2->setGeometry(x,y,ui->label_2->width(),ui->label_2->height());
}

void Dialog::venus()
{
    static int x = ui->label_4->x();
    static int y = ui->label_4->y();
    static bool banx = true;
    static bool bany = true;
    if(ui->label_4->x() == 1210)
        banx = false;
    if(ui->label_4->x() == 590)
        banx = true;
    if(banx){
        x++;
        if(ui->label_4->x() == 900)
            bany = false;
    }
    else{
        x--;
        if(ui->label_4->x() == 900)
            bany = true;
    }
    if(bany)
        y++;
    else
        y--;
    ui->label_4->setGeometry(x,y,ui->label_4->width(),ui->label_4->height());
}

void Dialog::tierra()
{
    static int x = ui->label_5->x();
    static int y = ui->label_5->y();
    static bool banx = true;
    static bool bany = true;
    if(ui->label_5->x() == 1340)
        banx = false;
    if(ui->label_5->x() == 460)
        banx = true;
    if(banx){
        x++;
        if(ui->label_5->x() == 900)
            bany = false;
    }
    else{
        x--;
        if(ui->label_5->x() == 900)
            bany = true;
    }
    if(bany)
        y++;
    else
        y--;
    ui->label_5->setGeometry(x,y,ui->label_5->width(),ui->label_5->height());
}

void Dialog::marte()
{
    static int x = ui->label_6->x();
    static int y = ui->label_6->y();
    static bool banx = true;
    static bool bany = true;
    if(ui->label_6->x() == 1460)
        banx = false;
    if(ui->label_6->x() == 340)
        banx = true;
    if(banx){
        x++;
        if(ui->label_6->x() == 900)
            bany = false;
    }
    else{
        x--;
        if(ui->label_6->x() == 900)
            bany = true;
    }
    if(bany)
        y++;
    else
        y--;
    ui->label_6->setGeometry(x,y,ui->label_6->width(),ui->label_6->height());
}

void Dialog::jupiter()
{
    static int x = ui->label_7->x();
    static int y = ui->label_7->y();
    static bool banx = true;
    static bool bany = true;
    if(ui->label_7->x() == 1658)
        banx = false;
    if(ui->label_7->x() == 142)
        banx = true;
    if(banx){
        x++;
        if(ui->label_7->x() == 900)
            bany = false;
    }
    else{
        x--;
        if(ui->label_7->x() == 900)
            bany = true;
    }
    if(bany)
        y++;
    else
        y--;
    ui->label_7->setGeometry(x,y,ui->label_7->width(),ui->label_7->height());
}

void Dialog::saturno()
{
    static int x = ui->label_8->x();
    static int y = ui->label_8->y();
    static bool banx = true;
    static bool bany = true;
    if(ui->label_8->x() == 1770)
        banx = false;
    if(ui->label_8->x() == 30)
        banx = true;
    if(banx){
        x++;
        if(ui->label_8->x() == 900)
            bany = false;
    }
    else{
        x--;
        if(ui->label_8->x() == 900)
            bany = true;
    }
    if(bany)
        y++;
    else
        y--;
    ui->label_8->setGeometry(x,y,ui->label_8->width(),ui->label_8->height());
}

void Dialog::meteoro()
{
    static int x = QRandomGenerator::global()->bounded(1,1800);
    static int y = QRandomGenerator::global()->bounded(1,700);
    static int w = 10;
    static int h = 10;
    ui->label_9->setGeometry(x,y,w,h);
    x++;y++;w++;h++;
    if(y == 710){
        x = QRandomGenerator::global()->bounded(1,1800);
        y = QRandomGenerator::global()->bounded(1,700);
        w = 10;
        h = 10;
    }
}


void Dialog::on_verticalSlider_valueChanged(int value)
{
    timer1->stop();
    timer1->start(value);
}


#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void mover();
    void mercurio();
    void venus();
    void tierra();
    void marte();
    void jupiter();
    void saturno();
    void meteoro();
    void on_verticalSlider_valueChanged(int value);
    void paintEvent(QPaintEvent*evt);

private:
    Ui::Dialog *ui;
     QTimer *timer1;
     QTimer *timer2;

};
#endif // DIALOG_H

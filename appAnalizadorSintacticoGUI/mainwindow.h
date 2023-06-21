#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_actionGuardar_triggered();

    void on_actionAbrir_triggered();


    void on_textEdit_textChanged();



private:
    Ui::MainWindow *ui;
    QString fileNameToOpen;
    QFile *file;
};
#endif // MAINWINDOW_H

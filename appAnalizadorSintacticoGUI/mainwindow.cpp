#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "analizadorlexico.h"
#include <QFileDialog>
#include <QMessageBox>
#include "analizadorsintactico.cpp"
#include <QTextStream>
#include <iostream>
#include <QStringList>
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_actionGuardar_triggered(){
    QString filename = QFileDialog::getSaveFileName(this, tr("Guardar Archivo"), "", tr("txt (*.ard);;All Files (*)"));
    QString texto = ui->textEdit->toPlainText();
    QFile file(filename);

    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << texto; //<<; endl;
    }
}

void MainWindow::on_actionAbrir_triggered(){
    FILE *parch;

        QString filter = "All File (*)";
        QString fileName = QFileDialog::getOpenFileName(this, "Elige un archivo", "/Users/USUARIO/Desktop", filter);

        fileNameToOpen = fileName;

        QFile file(fileName);

        if(!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Eleccion cancelada", "El archivo no fue abierto");
        }

        AnalizadorSintactico AnalisisSintactico;
        Analizador AnalizadorLexico;
        char archivoPath[200];
        strcpy(archivoPath, fileName.toStdString().c_str());
        QString aux;
        QString aux2;
        char cadenaChar[999];
        int renglonActual = 0;
        int columnaActual = 0;

        AnalizadorLexico.resetTable(ui->tableWidget);

        if((parch = fopen(archivoPath, "r")) != NULL) {


            QTextStream stream(parch);
            while(!stream.atEnd())
            {
                aux = stream.readLine();
                aux2 += aux;

                strcpy(cadenaChar, aux.toStdString().c_str());
                ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
                ui->tableWidget->setHorizontalHeaderItem(columnaActual, new QTableWidgetItem(cadenaChar));
                ui->tableWidget->setColumnWidth(columnaActual,200);

                AnalizadorLexico.scanner(cadenaChar, ui->tableWidget, renglonActual, columnaActual);

                columnaActual++;
                renglonActual = 0;


            }


            fclose(parch);

            ui->textEdit->setText(aux2);
            ui->statusbar->showMessage(fileName);

            //AnalisisSintactico.analizar();

    }else{
    QMessageBox::critical(this, "ERROR", "NO SE ENCONTRÓ EL ARCHIVO");
    }
}

void MainWindow::on_textEdit_textChanged()
{
    QString texto = ui->textEdit->toPlainText();
    if(texto.size() > 1){
        if(texto.at(texto.size()-1) == ";")
        {
            ui->tableWidget->setRowCount(0);
            ui->tableWidget->setColumnCount(0);
            ui->tableWidget_2->setRowCount(0);
            ui->tableWidget_2->setColumnCount(0);
            ui->tableWidget_3->setRowCount(0);
            ui->tableWidget_3->setColumnCount(0);

            Analizador analisisLexico;
            AnalizadorSintactico analisisSintactico;

            QString texto = ui->textEdit->toPlainText();
            vector<string> l;
            QStringList lista = texto.split(";");

            for (const QString& item : lista) {
                if(item != ";"){
                    l.push_back(item.toStdString()+";");
                }
            }
            int columnaActual = 0;
            analisisLexico.resetTable(ui->tableWidget);
            ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
            ui->tableWidget->setHorizontalHeaderItem(columnaActual, new QTableWidgetItem(texto));
            ui->tableWidget->setColumnWidth(columnaActual,200);

            int columnaActual2 = 0;
            int columnaActual3 = 0;

            ui->tableWidget_2->insertColumn(ui->tableWidget_2->columnCount());
            ui->tableWidget_2->setHorizontalHeaderItem(columnaActual2, new QTableWidgetItem("Producciones"));
            ui->tableWidget_2->setColumnWidth(columnaActual2,200);
            ui->tableWidget_3->insertColumn(ui->tableWidget_3->columnCount());
            ui->tableWidget_3->setHorizontalHeaderItem(columnaActual3, new QTableWidgetItem("X"));
            ui->tableWidget_3->setColumnWidth(columnaActual3,200);


            int pi = 0;
            for (int i = 0; i < l.size()-1 ; i++ ) {
                cout<<pi<<endl;
                char cadenaChar[999];
                strcpy(cadenaChar, l[i].c_str());
                analisisLexico.scanner(cadenaChar, ui->tableWidget, ui->tableWidget->rowCount(), columnaActual);
                analisisSintactico.ip = pi;
                analisisSintactico.analizar(analisisLexico.asTokens, ui->tableWidget_2, ui->tableWidget_3,ui->tableWidget_2->rowCount(),columnaActual2,ui->tableWidget_3->rowCount(), columnaActual3);
                //analiza a partir del ultimo ; analizado
                pi += analisisLexico.pal +1;
            }
        }
    }
}



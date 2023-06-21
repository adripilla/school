#include "analizadorlexico.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define leerCar(i) cadena[i++] //PROPORCIONA EL SIGUIENTE CARACTER
#define retrocedeCar i-- //REPRESENTA EL * PARA RETROCEDER UNA POSICION EN LA CADENA

//CONSTRUCTOR DE LA CLASE ANALIZADOR
Analizador::Analizador(){

}
//MÉTODO INICIALIZAR ESTADOS
void Analizador::inicializaEstados(){
    // Inicializa los estados del analizador léxico
    estadoInicial = estadoActual = 0;

}

bool Analizador::estadoDeAceptacion(){
    // Comprueba si el estado actual es un estado de aceptación

    switch (estadoActual)
    {
        case 2:
        case 5:
        case 8:
        case 10:
        case 13:
        case 14:
        case 18:
        case 19:
        case 23:
        case 24:
        case 28:
        case 29:
        case 32:
        case 35:
        case 38:
        case 41:
        case 43:
        case 45:
        case 47:
        case 49:
        case 51:
        case 53:
        case 56:
            return true;
        default : return false;
    }
}

void Analizador::fallo()
/*se utiliza para manejar las acciones necesarias cuando se produce un fallo
 en el análisis léxico, según los casos especificados en el switch del código.*/
{
/*
Es un método de la clase Analizador que no devuelve ningún valor (void).
Este método se encarga de realizar acciones específicas cuando se produce
un fallo en el análisis léxico. Realiza acciones específicas dependiendo del estado inicial
*/

    switch(estadoInicial)
   //Se realiza una comprobación basada en el valor del estado inicial.

    {

 /*Se enumeran los casos para los diferentes valores del estado inicial.
Cada caso establece un nuevo valor para el estado inicial y reinicia el índice i al inicio del token.
*/
        case 0: {

            estadoInicial = 3;
            i = inicioToken;

        } break;

        case 3: {

            estadoInicial = 6;
            i = inicioToken;

        } break;

        case 6: {

            estadoInicial = 11;
            i = inicioToken;

        } break;

        case 11: {

            estadoInicial = 15;
            i = inicioToken;

        } break;

        case 15: {

            estadoInicial = 20;
            i = inicioToken;

        } break;

        case 20: {

            estadoInicial = 25;
            i = inicioToken;

        } break;

        case 25: {

            estadoInicial = 30;
            i = inicioToken;

        } break;

        case 30: {

            estadoInicial = 33;
            i = inicioToken;

        } break;

        case 33: {

            estadoInicial = 36;
            i = inicioToken;

        } break;

        case 36: {

            estadoInicial = 39;
            i = inicioToken;

        } break;

        case 39: {

            estadoInicial = 42;
            i = inicioToken;

        } break;

        case 42: {

            estadoInicial = 44;
            i = inicioToken;

        } break;

        case 44: {

            estadoInicial = 46;
            i = inicioToken;

        } break;

        case 46: {

            estadoInicial = 48;
            i = inicioToken;

        } break;

        case 48: {
            estadoInicial=50;
            i = inicioToken;
        } break;

        case 50: {
            estadoInicial=52;
            i = inicioToken;
        } break;
    case 52: {
        estadoInicial=54;
        i = inicioToken;
    } break;
    case 54: {
        estadoInicial=0;
        i = inicioToken;
    } break;

     }

/*Después de actualizar el estado inicial, el estado actual
  también se actualiza con el mismo valor.*/

    estadoActual = estadoInicial;
}

/*
 * Es un método de la clase Analizador que toma un carácter c como parámetro
 * y devuelve un valor booleano (true o false). Este método verifica si el
 * carácter dado es un delimitador ' ', '\t', '\n'.
 * El método esDelimitador se utiliza para verificar si un carácter dado es
 * un delimitador en el contexto del análisis léxico. Los delimitadores
 * son caracteres utilizados para separar o delimitar tokens en una cadena de entrada.
*/
bool Analizador::esDelimitador(char c)
// método llamado esDelimitador en la clase Analizador
 // Verifica si el carácter es un delimitador
{
    if(c == ' ' || c == '\t' || c == '\n') {
        return true;
    }

    return false;
}

/*
 *  Es un método de la clase Analizador que devuelve un valor booleano
 *  (true o false). Este método verifica si el contenido de sLexema
 *  coincide con alguna de las palabras reservadas almacenadas en PalRes.
 */
bool Analizador::esPalRes()
{
    bool found = false;
    for(int k = 0; k < 4 && !found;){
        if(strcmp(PalRes[k],sLexema)==0)
            found = true;
        else
            k++;
    }
    return found;
}

void Analizador::scanner(char cadena[255], QTableWidget *table, int renglon, int columna)
{
    pal = 0;
    char caracter;

    inicializaEstados();
    i = inicioToken = 0;
    while( i < (int) strlen(cadena) || estadoDeAceptacion()) {

        switch(estadoActual) {
            case 0: {
                caracter = leerCar(i);

                if(esDelimitador(caracter)) {
                    estadoActual = 1;
                } else {
                    fallo();
                }

            } break;

            case 1: {

                caracter = leerCar(i);

                if(esDelimitador(caracter)) {
                    estadoActual = 1;
                } else {
                    estadoActual = 2;
                }

            } break;

            case 2: {
                retrocedeCar;
                inicioToken = i;
                inicializaEstados();                

            } break;

            case 3: {

                caracter = leerCar(i);

                if(isalpha(caracter) || caracter == '_') {
                    cont = 0;
                    sLexema[cont]=caracter;
                    estadoActual = 4;
                    cont++;
                } else {
                    fallo();
                }

            } break;

            case 4: {

                caracter = leerCar(i);

                if(isalpha(caracter) || caracter == '_' || isdigit(caracter) || caracter == '0') {
                    //cont = 0;
                    sLexema[cont]=caracter;
                    estadoActual = 4;
                    cont++;
                } else {
                    estadoActual = 5;
                }

            } break;

            case 5: {
                retrocedeCar;

                if(esPalRes()){
                    pal++;
                    table->insertRow(table->rowCount());
                    QString cad = sLexema;
                    table->setItem(renglon,columna,new QTableWidgetItem(cad));
                    strcpy(asTokens[token++],sLexema);
                    renglon++;
                    for(int h = 0; h <= cont; h++)
                        sLexema[h]= NULL;
                }else{
                    pal++;
                    table->insertRow(table->rowCount());
                    QString cad = "id";
                    table->setItem(renglon,columna,new QTableWidgetItem(cad));
                    strcpy(asTokens[token++],"id");
                    renglon++;
                    for(int h = 0; h <= cont; h++)
                        sLexema[h]= NULL;
                }

                inicioToken = i;
                inicializaEstados();
            } break;

            case 6: {

                caracter = leerCar(i);

                if(isdigit(caracter) || caracter == '0') {
                    estadoActual = 7;
                } else {
                    fallo();
                }

            } break;

            case 7: {

                caracter = leerCar(i);

                if(isdigit(caracter) || caracter == '0') {
                    estadoActual = 7;
                } else if(caracter == '.') {
                    estadoActual = 9;
                } else {
                    estadoActual = 8;
                }

            } break;

            case 8: {

                retrocedeCar;

                pal++;
                table->insertRow(table->rowCount());
                QString cad = "num";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"num");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            } break;

            case 9: {

                caracter = leerCar(i);

                if(isdigit(caracter) || caracter == '0' || caracter == '0') {
                    estadoActual = 9;
                } else {
                    estadoActual = 10;
                }

            } break;

            case 10: {

                retrocedeCar;

                pal++;
                table->insertRow(table->rowCount());
                QString cad = "numreal";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"numreal");
                renglon++;


                inicioToken = i;
                inicializaEstados();
            } break;

            case 11: {

                caracter = leerCar(i);

                if(caracter == '!') {
                    estadoActual = 12;
                } else {
                    fallo();
                }

            } break;

            case 12: {

                caracter = leerCar(i);

                if(caracter == '=') {
                    estadoActual = 13;
                } else {
                    estadoActual = 14;
                }
            } break;

            case 13: {
            pal++;
                table->insertRow(table->rowCount());
                QString cad = "!=";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"!=");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            } break;

            case 14: {
            pal++;
            table->insertRow(table->rowCount());
            QString cad = "!";
            table->setItem(renglon,columna,new QTableWidgetItem(cad));
            strcpy(asTokens[token++],"!");
            renglon++;

            inicioToken = i;
            inicializaEstados();
            } break;

            case 15: {
                caracter = leerCar(i);

                if(caracter == '=') {
                    estadoActual = 16;
                } else {
                    fallo();
                }
            } break;

            case 16: {
                caracter = leerCar(i);

                if(caracter == '=') {
                    estadoActual = 17;
                } else {
                    estadoActual = 18;
                }
            } break;

            case 17: {

                caracter = leerCar(i);

                if(caracter && caracter != '=') {
                    estadoActual = 19;
                }
            } break;

            case 18: {

                retrocedeCar;

                pal++;
                table->insertRow(table->rowCount());
                QString cad = "=";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"=");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            } break;

            case 19: {
                retrocedeCar;

                pal++;
                table->insertRow(table->rowCount());
                QString cad = "==";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"==");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            } break;

            case 20: {
                caracter = leerCar(i);

                if(caracter == '>') {
                    estadoActual = 21;
                } else {
                    fallo();
                }
            } break;

            case 21: {
                caracter = leerCar(i);

                if(caracter == '=') {
                    estadoActual = 22;
                } else {
                    estadoActual =24;
                }

            } break;

            case 22: {
                caracter = leerCar(i);

                if(caracter && caracter != '=') {
                    estadoActual = 23;
                }
            } break;

            case 23: {
                retrocedeCar;

                pal++;
                table->insertRow(table->rowCount());
                QString cad = ">=";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],">=");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            } break;

            case 24: {
                retrocedeCar;

                pal++;
                table->insertRow(table->rowCount());
                QString cad = ">";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],">");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            } break;

            case 25: {
                caracter = leerCar(i);

                if(caracter == '<'){
                    estadoActual = 26;
                }else{
                    fallo();
                }
            } break;

            case 26: {

                caracter = leerCar(i);

                if(caracter && caracter == '=') {
                    estadoActual = 27;
                } else {
                    estadoActual = 29;
                }

            } break;

            case 27: {
                caracter = leerCar(i);

                if(caracter && caracter != '=') {
                    estadoActual = 28;
                }
            } break;

            case 28: {
                retrocedeCar;

                pal++;
                table->insertRow(table->rowCount());
                QString cad = "<=";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"<=");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            } break;

            case 29: {
                retrocedeCar;

                pal++;
                table->insertRow(table->rowCount());
                QString cad = "<";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"<");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            } break;

            case 30: {
                caracter = leerCar(i);

                if(caracter == '+'){
                    estadoActual = 31;
                }else{
                    fallo();
                }
            } break;

            case 31: {
                caracter = leerCar(i);

                if(caracter && caracter != '+'){
                    estadoActual = 32;
                }else{
                    fallo();
                }
            } break;

            case 32: {
                retrocedeCar;

                pal++;
                table->insertRow(table->rowCount());
                QString cad = "+";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"+");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            } break;

            case 33: {
                caracter = leerCar(i);

                if(caracter == '-'){
                    estadoActual = 34;
                }else{
                    fallo();
                }
            } break;

            case 34: {
                caracter = leerCar(i);

                if(caracter && caracter != '-'){
                    estadoActual = 35;
                }else{
                    fallo();
                }
            } break;

            case 35: {
                retrocedeCar;

                pal++;
                table->insertRow(table->rowCount());
                QString cad = "-";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"-");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            } break;

            case 36: {
                caracter = leerCar(i);

                if(caracter == '*'){
                    estadoActual = 37;
                }else{
                    fallo();
                }
            } break;

            case 37: {
                caracter = leerCar(i);

                if(caracter && caracter != '*'){
                    estadoActual = 38;
                }else{
                    fallo();
                }
            } break;

            case 38: {
                retrocedeCar;

                pal++;
                table->insertRow(table->rowCount());
                QString cad = "*";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"*");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            } break;

            case 39: {
                caracter = leerCar(i);

                if(caracter == '/'){
                    estadoActual = 40;
                }else{
                    fallo();
                }
            } break;

            case 40: {
                caracter = leerCar(i);

                if(caracter && caracter != '/'){
                    estadoActual = 41;
                }else{
                    fallo();
                }
            } break;

            case 41: {
                retrocedeCar;

                pal++;
                table->insertRow(table->rowCount());
                QString cad = "/";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"/");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            } break;

            case 42: {
                caracter = leerCar(i);

                if(caracter == ';'){
                    estadoActual = 43;
                }else{
                    fallo();
                }
            } break;

            case 43:{

            pal++;
                table->insertRow(table->rowCount());
                QString cad = ";";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],";");
                renglon++;
                cad = "$";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"$");
                renglon++;
                inicioToken = i;
                inicializaEstados();
            }break;

            case 44:{
                caracter = leerCar(i);

                if(caracter == '['){
                    estadoActual = 45;
                }else{
                    fallo();
                }
            }break;

            case 45:{
            pal++;
                table->insertRow(table->rowCount());
                QString cad = "[";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"[");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            }break;

            case 46:{
                caracter = leerCar(i);

                if(caracter == ']'){
                    estadoActual = 47;
                }else{
                    fallo();
                }
            }break;

            case 47:{
            pal++;
                table->insertRow(table->rowCount());
                QString cad = "]";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],"]");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            }break;

            case 48:{
                caracter = leerCar(i);

                if(caracter == ','){
                    estadoActual = 49;
                }else{
                    fallo();
                }
            }break;

            case 49:{
            pal++;
                table->insertRow(table->rowCount());
                QString cad = ",";
                table->setItem(renglon,columna,new QTableWidgetItem(cad));
                strcpy(asTokens[token++],",");
                renglon++;

                inicioToken = i;
                inicializaEstados();
            }break;


        case 50:{
            caracter = leerCar(i);

            if(caracter == '('){
                estadoActual = 51;
            }else{
                fallo();
            }
        }break;

        case 51:{
            pal++;
            table->insertRow(table->rowCount());
            QString cad = "(";
            table->setItem(renglon,columna,new QTableWidgetItem(cad));
            strcpy(asTokens[token++],"(");
            renglon++;

            inicioToken = i;
            inicializaEstados();
        }break;


        case 52:{
            caracter = leerCar(i);

            if(caracter == ')'){
                estadoActual = 53;
            }else{
                fallo();
            }
        }break;

        case 53:{
            pal++;
            table->insertRow(table->rowCount());
            QString cad = ")";
            table->setItem(renglon,columna,new QTableWidgetItem(cad));
            strcpy(asTokens[token++],")");
            renglon++;

            inicioToken = i;
            inicializaEstados();
        }break;

        case 54:{
            caracter = leerCar(i);

            if(caracter == '"'){
                estadoActual = 55;
            }else{
                fallo();
            }
        }break;

        case 55:{
            caracter = leerCar(i);
            if(caracter != '"'){
                estadoActual = 55;
            }else{
                estadoActual = 56;
            }
        }break;
        case 56:{
            pal++;
            table->insertRow(table->rowCount());
            QString cad = "Cte.Lit";
            table->setItem(renglon,columna,new QTableWidgetItem(cad));
            strcpy(asTokens[token++],"Cte.Lit");
            renglon++;

            inicioToken = i;
            inicializaEstados();
        }break;




        }
    }
}

void Analizador::resetTable(QTableWidget *table){
    table->setRowCount(0);
    table->setColumnCount(0);
    columnaActual = 0;
}





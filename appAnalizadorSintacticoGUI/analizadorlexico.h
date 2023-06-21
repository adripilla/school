#ifndef ANALIZADOR_H
#define ANALIZADOR_H
#include <QTableWidget>

class Analizador
{
    //DECLARACION DE VARIABLES

    int i, inicioToken, estadoInicial, estadoActual, columnaActual = 0, cont, token=0;
    char PalRes[4][10]= {"char", "float","int","puts"};//PALABRAS RESERVADAS
    char sLexema[127];//MÁXIMO DE CARACTERES
public:
    Analizador();


    char asTokens [100][100];

    void inicializaEstados();

    bool estadoDeAceptacion();

    void fallo();

    bool esDelimitador(char c);

    bool esPalRes();

    void scanner(char cadena[255], QTableWidget *table, int renglonActual, int columnaActual);

    void resetTable(QTableWidget *table);
    int pal;

};

#endif // ANALIZADOR_H

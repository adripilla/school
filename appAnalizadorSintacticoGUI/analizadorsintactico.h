#ifndef ANALIZADORSINTACTICO_H
#define ANALIZADORSINTACTICO_H

#define MAXTOKEN 100
#define MAX 50
#include <string>
#include "pila.cpp"
#include <string.h>
#include <QTableWidget>


class AnalizadorSintactico{
    void iniciaAsTokens(char aLexico[100][100]);

    Pila<std::string> *pila;
    //TERMINALES
    char token[26][8] = {"x",";",",","*","id","[","]","num","char","int","float","puts","(",")","Cte.Lit","numreal","=","==","!=",">=","<=",">","<","+","-","/"};
    //NO TERMINALES
    //                    0   1   2   3   4    5   6    7     8      9      10     11    12  13     14      15    16  17   18   19   20  21   22  23  24  25
    char varsint[14][3]={"x","D","L","L'","I","I'","A","A'","K","T","F","E","P","K'"};
    //                    0   1   2   3    4   5    6   7    8   9   10  11  12  13

                        //NT  T  NT   NT   NT   T
    int tablaM[44][8]= {{ 1,  8, 1,   9,   2,  -1, 999, 999},//D CHAR= D ->TL;
                        { 1,  9, 1,   9,   2,  -1, 999, 999},//D INT= D ->TL;
                        { 1, 10, 1,   9,   2,  -1, 999, 999},//D FLOAT= D ->TL;
                        { 2,  3, 2,   4,   3, 999, 999, 999},//L*=L ->IL'
                        { 2,  4, 2,   4,   3, 999, 999, 999},//L ID= L ->IL'
           /*05*/       { 3,  1, 3, 999, 999, 999, 999, 999},//L';=L'->ε
                        { 3,  2, 3,  -2,   4,   3, 999, 999},//L',= L'->,IL'
                        { 5, 16, 5, -16,  13, 999, 999, 999},//I'= = I'->=K'//Solo tomar 1 =
                        { 5, 17, 5, -17,  13, 999, 999, 999},//I'== = I'->==K'
                        { 5, 18, 5, -18,  13, 999, 999, 999},//I' != = I'->!=K'
           /*10*/       { 5, 19, 5, -19,  13, 999, 999, 999},//I' >= = I'->>=K'
                        { 5, 20, 5, -20,  13, 999, 999, 999},//I'<= = I'-><=K'
                        { 5, 21, 5, -21,  13, 999, 999, 999},//I'> = I'->>K'
                        { 5, 22, 5, -22,  13, 999, 999, 999},//I'< = I'-><K'
                        { 4,  3, 4,  -3,  -4,   5, 999, 999},//I* = I->*idI'
           /*15*/       { 4,  4, 4,  -4,   5, 999, 999, 999},//I ID =I ->idI'
                        { 5,  1, 5, 999, 999, 999, 999, 999},//I'; = I'->ε
                        { 5,  2, 5, 999, 999, 999, 999, 999},//I',= I'->ε
                        { 5,  5, 5,   6, 999, 999, 999, 999},//I'[ = I'->A
                        { 6,  5, 6,  -5,   8,  -6,   7, 999},//A[ = A ->[K]A'
           /*20*/       { 7,  1, 7, 999, 999, 999, 999, 999},//A'; = A'->ε
                        { 7,  2, 7, 999, 999, 999, 999, 999},//A',= A'->ε
                        { 7,  5, 7,  -5,   8,  -6,   7, 999},//A'[ = A'->[K]A'
                        { 8,  4, 8,  -4, 999, 999, 999, 999},//K ID= K ->id
                        { 8,  7, 8,  -7, 999, 999, 999, 999},//K num = K ->num
           /*25*/       { 8, 15, 8, -15, 999, 999, 999, 999},//K numreal = K ->numreal
                        {13,  1,13, 999, 999, 999, 999, 999},//K'; = K'->ε
                        {13,  3,13,  -3,  13, 999, 999, 999},//K'* = K'->*K'
                        {13,  7,13,  -7,  13, 999, 999, 999},//K' num = K'->numK'
                        {13, 15,13, -15,  13, 999, 999, 999},//K' numreal = K'->numreal K'
          /*30*/        {13, 23,13, -23,  13, 999, 999, 999},//K'+ = K'->+K'
                        {13, 24,13, -24,  13, 999, 999, 999},//K'- = K'->-K'
                        {13, 25,13, -25,  13, 999, 999, 999},//K'/ = K'->/K'
                        { 9,  8, 9,  -8, 999, 999, 999, 999},//T char = T ->char
                        { 9,  9, 9,  -9, 999, 999, 999, 999},//T int = T ->int
          /*35*/        { 9, 10, 9, -10, 999, 999, 999, 999},//T float = T ->float
        /*segunda gramatica */
                        {10, 11,10, -11,  11,  -1, 999, 999},//F puts =F ->putsE;
                        {11, 12,11, -12,  12, -13, 999, 999},//E( = E ->(P)
                        {12, 14,12, -14, 999, 999, 999, 999},//P Cte.Lit = P ->Cte.Lit
           /*39*/       {12,  4,12,  -4, 999, 999, 999, 999}, //P ID = P ->id

                        //AGREGADAS K'
                        {13, 4, 13, -4, 13, 999, 999, 999}, //idK'
                        {13, 12, 13, -12, 13, 999,999,999}, //K' -> (K'
                        {13, 13, 13, -13, 13, 999,999,999},  //K' -> )K'
                        {13, 14, 13, -14, 13, 999,999,999}  //K' -> Cte.Lit K'

    };

    char asTokens [MAXTOKEN][100];
    int cima = -1;
    char pilac[MAX][10];
public:
    AnalizadorSintactico();
    void analizar(char aLexico[100][100], QTableWidget *tablaSintactica, QTableWidget *tablaPila, int renActSin, int colActSin, int renActPil, int colActPil);
    int estoken(char x[]);
    int buscaTabla(char a[], char x[]);
    int ip;

};

#endif // ANALIZADORSINTACTICO_H

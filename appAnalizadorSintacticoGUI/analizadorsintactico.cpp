#include "analizadorsintactico.h"
#include "analizadorlexico.h"
#include <string>
#include <string.h>



void AnalizadorSintactico::iniciaAsTokens(char aL[100][100])
{
    for(int copiaR = 0; copiaR < 100;copiaR++){
           strcpy(asTokens[copiaR],aL[copiaR]);
    }
}

AnalizadorSintactico::AnalizadorSintactico(){

}

void AnalizadorSintactico::analizar(char aLexico[100][100], QTableWidget *tablaS, QTableWidget *tablaP, int renSin, int colSin, int renPil, int colPil)
{
    iniciaAsTokens(aLexico);
    pila = new Pila<std::string>(100);

    int  i, j;
    int renglon, iast;
    char x[10], a[10];
    pila->push("$");

    if(strcmp(asTokens[ip],"puts") == 0)
    {
        pila->push("F");
    }
    else
        pila->push("D");

    for(i = 0; strcmp(asTokens[i],"$") != 0; i++)
    {
        tablaS->setItem(renSin,colSin,new QTableWidgetItem(asTokens[i]));
    }
    do
    {
        strcpy(x,pila->Tope().c_str());
        strcpy(a,asTokens[ip]);

        if(estoken(x) || (strcmp(x,"$") == 0))
        {
            if(strcmp(x,a) == 0)
            {
                pila->pop();
                //if(strcmp(pila->Tope().c_str(),"$") == 0)
                if(pila->estaVacia())
                {
                    tablaS->insertRow(tablaS->rowCount());
                    tablaS->setItem(renSin,colSin,new QTableWidgetItem("Sintaxis correcta"));
                    renSin++;
                }else if(!strcmp(a,";")){
                    //printf("epsilon");
                    tablaS->insertRow(tablaS->rowCount());
                    tablaS->setItem(renSin,colSin,new QTableWidgetItem("-------Siguiente-------"));
                    renSin++;
                }
                ip++;
            }
            else
            {
                if(strcmp(asTokens[ip],"puts") == 0)
                {
                    pila->push("F");
                }
                else
                    pila->push("D");

                strcpy(x,pila->Tope().c_str());

            }
        }
        else  //sino es token
        {
            tablaP->insertRow(tablaP->rowCount());
            tablaP->setItem(renPil,colPil,new QTableWidgetItem(x));
            renPil++;
            renglon = buscaTabla(a,x);
            if(renglon != 999)
            {
                QString mensaje;
                pila->pop();
                iast = 0;
                mensaje = varsint[tablaM[renglon][0]];
                mensaje.append("->");

                for(j= 3; iast != 999; j++)
                {
                    iast = tablaM[renglon][j];  //999

                    if(iast < 0)
                    {
                        iast *= -1;
                        //printf("%s ",token[iast]);
                        mensaje.append(token[iast]);
                        tablaS->insertRow(tablaS->rowCount());
                        tablaS->setItem(renSin,colSin,new QTableWidgetItem(mensaje));
                        renSin++;
                    }
                    else
                    {
                        if(iast !=999)
                        {
                            mensaje.append(varsint[iast]);
                            tablaS->insertRow(tablaS->rowCount());
                            tablaS->setItem(renSin,colSin,new QTableWidgetItem(mensaje));
                            renSin++;
                        }
                    }
                }

                for(i = j-2; i > 2; i--)
                {
                    iast = tablaM[renglon][i];

                    if(iast < 0)
                    {
                        iast *= -1;
                        pila->push(token[iast]);
                    }
                    else
                        pila->push(varsint[iast]);
                }
            }
            else
            {
                tablaS->insertRow(tablaS->rowCount());
                QString error = QString::number(ip);

                tablaS->setItem(renSin,colSin,new QTableWidgetItem("Error de Sintaxis "+error));
                renSin++;
                return;
            }
        }
    }
    while(strcmp(x,"$")!= 0);
}

int AnalizadorSintactico::buscaTabla(char a[], char x[])
{
    int indx = 0, inda = 0, i;

    for(i = 0; i < 26; i++)
    {
        if(strcmp(a,token[i]) == 0)
        {
            inda = i;
            break;
        }
    }

    for(i = 0; i < 14; i++)
    {
        if(strcmp(x,varsint[i]) == 0)
        {
            indx = i;
            break;
        }
    }

    for(i = 0; i < 44; i++)
    {
        if(indx == tablaM[i][0])
        {
            if(inda == tablaM[i][1])
            {
                return i;
            }
        }
    }
    return 999;
}

int AnalizadorSintactico::estoken(char x[])
{
    int i;
    for(i = 0; i < 26; i++)
    {
        if(strcmp(x,token[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

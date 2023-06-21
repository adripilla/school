#include "mapeo.h"


//mapeo::mapeo()
//{
//
//}

void Mapeo::ventana(float wx1, float wy1, float wx2, float wy2)
{
    xWmin = wx1;
    yWmin = wy1;
    xWmax = wx2;
    yWmax = wy2;
}

void Mapeo::puerto(int pvX1, int pvY1, int pvX2, int pvY2)
{
    xpVmin = pvX1;
    ypVmin = pvY1;
    xpVmax = pvX2;
    ypVmax = pvY2;
}

void Mapeo::mapear(float *xw, float *yw, int *xpV, int &ypV, int L, int M)
{
    float sX, sY;
    sX = (xpVmax - xpVmin)/(xWmax - xWmin);
    cout << "Escalacion en X = " << sX << endl;
    sY = (ypVmax - ypVmin)/(yWmax - yWmin);
    cout << "Escalacion en Y = " << sY << endl;
    *xpV = int(round(sX*(*xw-xWmin)+xpVmin)+L);
    ypV = int(round(sY*(yWmin-*yw)-ypVmin)+M);
    //NOTA: L y M representan el origen a partir del cual vamos a dibujar
}

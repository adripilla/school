#ifndef MAPEO_H
#define MAPEO_H

#include <iostream>

using namespace std;

class Mapeo
{

    float xWmin, yWmin, xWmax, yWmax;
    int xpVmin, ypVmin, xpVmax, ypVmax;


public:
    //mapeo();
    int round(float n) {return n+0.5;}
    void ventana(float wx1, float wy1, float wx2, float wwy2);
    void puerto(int pvX1, int pvY1, int pvX2, int pvY2);
    void mapear(float *xw, float *yw, int *xpV, int &ypV, int L, int M);
};

#endif // MAPEO_H

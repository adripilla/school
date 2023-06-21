#ifndef PILA_H
#define PILA_H

template <class T>
class Pila
{
    //VARIABLES
    T *vec;
    int tam;
    int tope;
    bool vacia;
    bool llena;

public:
    //MÉTODOS
    Pila(int n);

    void push(T valor);
    T pop();
    bool estaVacia();
    bool estaLlena();
    T Tope();

};

#endif // PILA_H

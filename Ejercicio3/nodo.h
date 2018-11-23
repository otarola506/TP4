#ifndef NODO_H
#define NODO_H

using namespace std ;

class Nodo {

int dato ;
Nodo *siguiente ;

public :
    Nodo() {dato=0 ;siguiente = nullptr ;} ;
    Nodo(int x) {dato= x;siguiente = nullptr ;};
    void SetSiguiente(Nodo *n) { siguiente=n;};
    Nodo *GetSiguiente() { return siguiente ;};
    void SetDato(int dato) {this->dato=dato ;} ;
    int GetDato()  ;
};

#endif


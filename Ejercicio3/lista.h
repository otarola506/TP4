#ifndef LISTA_H
#define LISTA_H
#include <iostream>

using namespace std;
#include "nodo.h"


class Lista {
    Nodo *cabeza ;
    int cNodos;
public:    
    Lista() {cabeza= NULL ;} ;
    void Insertar(int x) ;
    void Imprimir() ;
    void Modificar(int posicion, int dato);
    //void EliminarDato(int x) ; //elimina el dato x 
    //void EliminarPosicion(int i) ; //elimina la posicion i 
    
    ~Lista() {delete cabeza ;} ;
};
#endif

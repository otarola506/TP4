#ifndef POBLACION_H
#define POBLACION_H
#include "lista.h"
class Poblacion{
    Lista laPoblacion;
    int aptitud;
    Public:
    Poblacion(){
        aptitud=-1;
    }
    void AgregarCiudad(int ciudad){
        laPoblacion.Insertar(ciudad);
    }
}
#endif // POBLACION_H

#ifndef ALGORITMOGPAG_H
#define ALGORITMOGPAG_H
#include "agenteviajero.h"
#include <iostream>
#include <time.h>
using namespace std;
class AlgoritmoG{
   Poblacion laPoblacion[130];
    int generadorX;
    int generadorY;
public:
    AlgoritmoG(){
        for(int i=0;i<100;i++){
            generadorX = rand() % 200 + 1;
            generadorY = rand() % 200 + 1;
            Poblacion temp(generadorX,generadorY);
            laPoblacion[i]=temp;
        }
      for(int i=0;i<1000000000;i++){
         cruzar();
         mutar();
         aptitud();
         seleccionar();
         cout<<i<<endl;
      }
    }

#endif // ALGORITMOGPAG_H

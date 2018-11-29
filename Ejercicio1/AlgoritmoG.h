#ifndef ALGORITMOG_H
#define ALGORITMOG_H
#include "poblacion.h"
#include <iostream>
//#include <time.h>
#include "polinomio.h"

using namespace std;

class AlgoritmoG{
   Poblacion laPoblacion[130];
    int generadorX;
    int generadorY;
    Polinomio *polinomioA;
public:
    AlgoritmoG(){
        polinomioA = new Polinomio();
        for(int i=0;i<100;i++){
            generadorX = rand() % 200 + 1;
            generadorY = rand() % 200 + 1;
            Poblacion temp(generadorX,generadorY);
            laPoblacion[i]=temp;
        }
      for(int i=0;i<3;i++){
         cruzar();
         mutar();
         aptitud();
         seleccionar();
      }
    }

    void cruzar(){
        for(int i=0;i<30;i++){
            int randomA = rand() % 100;
            int randomB = rand() % 100;
            Poblacion temp(randomA,randomB);
            laPoblacion[100+i] = temp;
        }
    }

    void mutar(){
        for(int i=0;i<30;i++){
            int random = rand() % 30;
            laPoblacion[100+i].setX(laPoblacion[random].getX()+1);
        }
    }

    void aptitud(){
        polinomioA->Derivar();
        int g = polinomioA->CantidadMonomiosDerivada();
        int ress = 0;
        int numeroNuevo;
        for(int c = 0; c <130; c++){
            int valorX = laPoblacion[c].getX();
            int valorY = laPoblacion[c].getY();
           for(int i=0;i<g;i++){
               numeroNuevo = polinomioA->GetDato(i,0);
               for(int q = 0; q < polinomioA->GetDato(g,1)-1; q++){
                    valorX = valorX*valorX;
               }
               for(int t = 0; t < polinomioA->GetDato(g,2)-1; t++){
                    valorY = valorY*valorY;
               }
               numeroNuevo = numeroNuevo*valorX*valorY;
               ress = ress + numeroNuevo;
            }
           laPoblacion[c].setApti(ress);
        }
    }

    void seleccionar(){
        Poblacion sustituta[100];
        for(int i=0;i<85;i++){
            int temp=0;
            int posicion=0;
            for(int j=0;j<130;j++){
                if(laPoblacion[j].getApti() > temp){
                    temp=laPoblacion[j].getApti();
                    posicion=j;
                }
            }
            sustituta[i]=laPoblacion[posicion];
            laPoblacion[posicion].setApti(-1);
        }

        for(int i=0;i<15;i++){
            int temp=1000000;
            int posicion=0;
            for(int j=0;j<130;j++){
                if(laPoblacion[j].getApti()<temp&&laPoblacion[j].getApti()!=-1){
                    temp=laPoblacion[j].getApti();
                    posicion=j;
                }
            }
            sustituta[i+85]=laPoblacion[posicion];
            laPoblacion[posicion].setApti(-1);
        }

        for(int i=0;i<100;i++){
            laPoblacion[i]=sustituta[i];
        }

        for(int i=100;i<130;i++){
            laPoblacion[i].setX(0);
            laPoblacion[i].setY(0);
            laPoblacion[i].setApti(-1);
        }
    }
};

#endif // ALGORITMOG_H

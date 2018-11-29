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
        polinomioA = new Polinomio("2x2y2+3x3y3+4x4y4"/*x*/);
        polinomioA->SepararMonomio();
        for(int i=0;i<100;i++){
            generadorX = rand() % 200 + 1;
            generadorY = rand() % 200 + 1;
            Poblacion temp(generadorX,generadorY);
            laPoblacion[i]=temp;
        }
      for(int i=0;i<10000;i++){
         cruzar();
         mutar();
         aptitud();
         seleccionar();
      }
      //for(int i=0; i<130; i++){
          cout << "------------";// laPoblacion[i].getApti() << endl;
      //}
    }

    void cruzar(){
        for(int i=0;i<30;i++){
            generadorX = rand() % 200 + 1;
            generadorY = rand() % 200 + 1;
            Poblacion temp(laPoblacion[generadorX].getX(),laPoblacion[generadorY].getY());
            laPoblacion[101+i]=temp;
        }
    }

    void mutar(){
        for(int i=0;i<26;i++){
            generadorX = rand() % 200 + 1;
            int temp=laPoblacion[generadorX].getX();
            laPoblacion[generadorX].setX(temp+1);
        }
    }

    void aptitud(){
        polinomioA->Derivar();
        int g = polinomioA->CantidadMonomiosDerivada();
        int ress = 0;
        int numeroNuevo;
        for(int c = 0; c<131; c++){
            int valorX = laPoblacion[c].getX();
            int valorY = laPoblacion[c].getY();
           for(int i=0;i<g;i++){
               numeroNuevo = polinomioA->GetDato(i,0);
               for(int q = 0; q < polinomioA->GetDato(c,1)-1; q++){
                    valorX = valorX*valorX;
               }
               for(int t = 0; t < polinomioA->GetDato(c,2)-1; t++){
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
        for(int i=0;i<86;i++){
            int temp=0;
            int posicion=0;
            for(int j=0;j<131;j++){
                if(laPoblacion[j].getApti() > temp){
                    temp=laPoblacion[j].getApti();
                    posicion=j;
                }
            }
            sustituta[i]=laPoblacion[posicion];
            laPoblacion[posicion].setApti(-1);
        }

        for(int i=0;i<16;i++){
            int temp=1000000;
            int posicion=0;
            for(int j=0;j<131;j++){
                if(laPoblacion[j].getApti()<temp&&laPoblacion[j].getApti()!=-1){
                    temp=laPoblacion[j].getApti();
                    posicion=j;
                }
            }
            sustituta[i+85]=laPoblacion[posicion];
            laPoblacion[posicion].setApti(-1);
        }

        for(int i=0;i<101;i++){
            laPoblacion[i]=sustituta[i];
        }

        for(int i=101;i<130;i++){
            laPoblacion[i].setX(0);
            laPoblacion[i].setY(0);
            laPoblacion[i].setApti(-1);
        }
    }
};

#endif // ALGORITMOG_H

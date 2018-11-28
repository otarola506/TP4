#ifndef ALGORITMOG_H
#define ALGORITMOG_H
#include "poblacion.h"
#include <iostream>
#include <time.h>
#include "polinomio.h"

using namespace std;

class AlgoritmoG{
   Poblacion laPoblacion[130];
    int generadorX;
    int generadorY;
    Polinomio *polinomioA;
public:
    AlgoritmoG(){
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
         cout<<i<<endl;
      }
      polinomioA = new Polinomio("2x2y3+3x3y9+4x4y8");
      polinomioA->SepararMonomio();
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
        for(int i=0;i<131;i++){
            int temp;
            for(int j = 0; j < 10; j++){
                if(polinomioA->GetDato(j,0) != 0){
                    temp = polinomioA->GetDato(j,0);
                    int valorX = laPoblacion[i].getX();
                    int valorY = laPoblacion[i].getY();
                    for(int q = 0; q < polinomioA->GetDato(j,1)-1; q++){
                        valorX = valorX*polinomioA->GetDato(j,1);
                    }
                    for(int t = 0; t < polinomioA->GetDato(j,2)-1; t++){
                        valorY = valorY*polinomioA->GetDato(j,2);
                    }
                    temp = temp*valorX*valorY;
                }
            }
            laPoblacion[i].setApti(temp);
        }
    }
    void seleccionar(){
        Poblacion sustituta[100];
        for(int i=0;i<86;i++){
            int temp=0;
            int posicion=0;
            for(int j=0;j<131;j++){
                if(laPoblacion[j].getApti()>temp){
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

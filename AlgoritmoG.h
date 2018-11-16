#ifndef ALGORITMOG_H
#define ALGORITMOG_H
#include "poblacion.h"
#include <iostream>
#include <time.h>
using namespace std;
class AlgoritmoG(){
   poblacion laPoblacion[130];
    int generadorX;
    int generadorY;
    srand (time(NULL));
    AlgoritmoG(int x){
        for(int i=0;i<100;i++){
            generadorX = rand() % 200 + 1;
            generadorY = rand() % 200 + 1;
            poblacion[i]=poblacion(generadorX,generadorY);
        }

    }
    void cruzar(){
        for(int i=0;i<30;i++){
            generadorX = rand() % 200 + 1;
            generadorY = rand() % 200 + 1;
            poblacion[101+i]=poblacion((poblacion[generadorX].getX()),(poblacion[generadorY].getY()));
        }
    }
    void mutar(){
        for(int i=0;i<26;i++){
            generadorX = rand() % 200 + 1;
            int temp=poblacion[generadorX].getX();
            poblacion[generadorX].setX(temp+1);
        }
    }
    void aptitud(){
        for(int i=0;i<131;i++){
            int temp=2*poblacion[i].getX()*poblacion[i].getX()**poblacion[i].getY()*poblacion[i].getY()+1;//el uno es el resto del polinomio
            poblacion[i].setApti(temp);
        }
    }
    void seleccionar(){
        poblacion sustituta[100];
        for(int i=0;i<86;i++){
            int temp=0;
            int posicion=0;
            for(int j=0;j<131;j++){
                if(poblacion[j].getApti()>temp){
                    temp=poblacion[j].getApti();
                    posicion=j;
                }
            }
            sustituta[i]=poblacion[posicion];
            poblacion[posicion].setApti(-1);
        }
        for(int i=0;i<16;i++){
            int temp=1000000;
            int posicion=0;
            for(int j=0;j<131;j++){
                if(poblacion[j].getApti()<temp&&poblacion[j].getApti()!=-1){
                    temp=poblacion[j].getApti();
                    posicion=j;
                }
            }
            sustituta[i+85]=poblacion[posicion];
            poblacion[posicion].setApti(-1);
        }
        for(int i=0;i<101;i++){
            poblacion[i]=sustituta[i];
        }
        for(int i=101;i<130;i++){
            poblacion[i].setX(0);
            poblacion[i].setY(0);
            poblacion[i].setApti(-1);
        }
    }
}

#endif // ALGORITMOG_H

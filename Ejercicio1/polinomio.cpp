#include "Polinomio.h"
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

Polinomio::Polinomio()
{
   cout << "Digite el polinomio separado por +, en caso de restas adjuentelo +-. Ej: 2x2y2+3x3y3+4x4y4 Valido para digitos entre 1 y 9";
   string x;
   cin >> x;
   polinomio = x;
   cantMonomiosDerivada = 0;
   matriz[10][3];
   for(int i = 0; i < 10; i++){
       matriz[i][0] = 0;
       matriz[i][1] = 0;
       matriz[i][2] = 0;
   }
   SepararMonomio();
}

void Polinomio:: SepararMonomio()
{
    int n = polinomio.length();
    char cadena[n+1];
    strcpy(cadena, polinomio.c_str());
    int contador = 0;
    for(int i = 0; i < n; i++){
        if(cadena[i]== 'x'){
           int numP = cadena[i-1] -48;
           int numX = cadena[i+1] -48;
           int numY= cadena[i+3] -48;
           matriz[contador][0] = numP;
           matriz[contador][1] = numX;
           matriz[contador][2] = numY;
           contador++;
         }
     }
}

void Polinomio::CambiarCoeficiente(int coeficiente, int gradoX, int gradoY)
{
   for(int i=0; i<10; i++){
       if(matriz[i][1] == gradoX && matriz[i][2] == gradoY)
       {
           matriz[i][0] = coeficiente;
       }
   }
}

void Polinomio::EliminarGrado(int grado)
{
   for(int i=0; i<10; i++){
       if(matriz[i][1] == grado)
       {
           matriz[i][1] = 0;
           matriz[i][0] = 0;
       }
       if(matriz[i][3] == grado)
       {
           matriz[i][2] = 0;
           matriz[i][3] = 0;
       }
   }
}

bool Polinomio::Consultar(int expo)
{
   bool respuesta;
   int a = 0;
   for(int i=0; i<10; i++){
       if(matriz[i][1] == expo)
       {
           respuesta = true;
           a = 50;
       }
       if(matriz[i][3] == expo)
       {
           respuesta = true;
           a = 50;
       }
   }
   if(a < 45)
   {
       respuesta = false;
   }
   return respuesta;
}

string Polinomio::Imprimir()
{
   string respuesta;
   for(int i=0; i<10; i++){
       stringstream x;
       if(matriz[i][1] != 0 && matriz[i][2] != 0)
       {
           x << matriz[i][0] << " " << matriz[i][1] << " " << matriz[i][2] << "\n";
       }
       respuesta += x.str();
   }
   return respuesta;
}

void Polinomio::Agregar(int coeficiente, int exponenteX, int exponenteY)
{
    for(int i=0; i<10; i++){
        if(matriz[i][1] == 0 && matriz[i][2] == 0)
        {
            matriz[i][0] = coeficiente;
            matriz[i][1] = exponenteX;
            matriz[i][2] = exponenteY;
        }
    }
}

void Polinomio::Modificar(int coeficiente, int exponenteX, int exponenteY)
{
   for(int i=0; i<10; i++){
       if(matriz[i][1] == exponenteX && matriz[i][2] == exponenteY)
       {
           matriz[i][0] = coeficiente;
       }
   }
}

int Polinomio::GetCoeficiente(int expoX, int expoY)
{
   int r = 0;
   for(int i = 0; i < 10; i++)
   {
       if(matriz[i][1] == expoX && matriz[i][2] == expoY){
           r = matriz[i][0];
           i = 10;
       }
   }
   return r;
}

int Polinomio::GetExponenteX(int coefi)
{
   int r = 0;
   for(int i = 0; i < 10; i++)
   {
       if(matriz[i][0] == coefi){
           r = matriz[i][1];
           i = 10;
       }
   }
   return r;
}

int Polinomio::GetExponenteY(int coefi)
{
   int r = 0;
   for(int i = 0; i < 10; i++)
   {
       if(matriz[i][0] == coefi){
           r = matriz[i][2];
           i = 10;
       }
   }
   return r;
}

string Polinomio::ImprimirPolinomio()
{
   string resp = "";
   for(int i=0; i<10; i++){
       stringstream x;
       if(matriz[i][1] != 0)
       {
           x << matriz[i][0] << "x" << matriz[i][1] << "y" << matriz[i][2] << "+";
       }
       resp += x.str();
   }
   return resp;
}

int Polinomio::GetExponenteMayorX()
{
   int resp = 0;
   for(int i=0; i<10; i++)
   {
       int a = matriz[i][1];
       if(resp < a)
       {
           resp = a;
       }
   }
   return resp;
}

int Polinomio::GetExponenteMayorY()
{
   int resp = 0;
   for(int i=0; i<10; i++)
   {
       int a = matriz[i][2];
       if(resp < a)
       {
           resp = a;
       }
   }
   return resp;
}

void Polinomio::Derivar()
{
    for(int i=0; i<10; i++){
        if(matriz[i][0]!=0){
            matriz[i][0] = matriz[i][0] * matriz[i][1] * matriz[i][2];
            matriz[i][1] = matriz[i][1] - 1;
            matriz[i][2] = matriz[i][2] - 1;
            cantMonomiosDerivada++;
        }
    }
}

int Polinomio::GetDato(int a, int b)
{
    int resp = matriz[a][b];
    return resp;
}

int Polinomio::CantidadMonomiosDerivada()
{
    return cantMonomiosDerivada;
}

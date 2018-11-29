#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <iostream>

using namespace std;

class Polinomio{
    public:
       Polinomio();
       string polinomio;
       int cantMonomiosDerivada;
       int matriz[10][3];
       void SepararMonomio();
       string Imprimir();
       void CambiarCoeficiente(int coeficiente, int gradoX, int gradoY);
       void EliminarGrado(int grado);
       bool Consultar(int expo);
       void Agregar(int coeficiente, int coeficienteY, int exponenteY);
       void Modificar(int coeficiente, int exponenteX, int exponenteY);
       int GetExponenteX(int coefi);
       int GetExponenteY(int coefi);
       int GetCoeficiente(int expoX, int expoY);
       string ImprimirPolinomio();
       int GetExponenteMayorX();
       int GetExponenteMayorY();
       void Derivar();
       int GetDato(int a, int b);
       int CantidadMonomiosDerivada();
};
#endif

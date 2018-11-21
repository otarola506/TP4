#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <iostream>

using namespace std;

class Polinomio{
    public:
       string polinomio;
       long matriz[10][4];
       Polinomio(string polinomioUsuario);
       void SepararMonomio();
       string Imprimir();
       void CambiarCoeficienteX(int coeficiente, int grado);
       void CambiarCoeficienteY(int coeficiente, int grado);
       void EliminarGrado(int grado);
       bool Consultar(int expo);
       void Agregar(int coeficienteX, int exponenteX, int coeficienteY, int exponenteY);
       void Modificar(int coeficienteX, int exponenteX, int coeficienteY, int exponenteY);
       int GetExponenteX(int coefi);
       int GetExponenteY(int coefi);
       int GetCoeficienteX(int expo);
       int GetCoeficienteY(int expo);
       string ImprimirPolinomio();
       int GetExponenteMayorX();
       int GetExponenteMayorY();
};
#endif

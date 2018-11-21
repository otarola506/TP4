#include "Polinomio.h"
#include <iostream>
//#include <wx/tokenzr.h>
#include <sstream>

using namespace std;

Polinomio::Polinomio(string polinomioUsuario)
{
   polinomio = polinomioUsuario;
   matriz[10][4];
   for(int i = 0; i < 10; i++){
       matriz[i][0] = 0;
       matriz[i][1] = 0;
       matriz[i][2] = 0;
       matriz[i][3] = 0;
   }
}

void Polinomio:: SepararMonomio()
{


















   long exponen = 0;
   long coef = 0;
   /*wxString coeficientes;
   wxString exponentes;
   wxString polinomioUsuario(polinomio);
       wxStringTokenizer t(polinomioUsuario, "+");
   int contador = 0;
   while ( t.HasMoreTokens() )
   {
       wxStringTokenizer m(t.GetNextToken(), "x");
       if(m.HasMoreTokens())
       {
           coeficientes = m.GetNextToken();

       }
       if(m.HasMoreTokens())
       {
           exponentes = m.GetNextToken();
       }
       wxString number(exponentes);*/
       //if(!number.ToLong(&exponen)) {/* error */};
       //wxString number1(coeficientes);
       //if(!number1.ToLong(&coef)) {/* error */};
       //matriz[contador][0] = coef;
       //matriz[contador][1] = exponen;
       //contador++;
   //}
}

void Polinomio::CambiarCoeficienteX(int coeficiente, int grado)
{
   for(int i=0; i<10; i++){
       if(matriz[i][1] == grado)
       {
           matriz[i][0] = coeficiente;
       }
   }
}

void Polinomio::CambiarCoeficienteY(int coeficiente, int grado)
{
   for(int i=0; i<10; i++){
       if(matriz[i][3] == grado)
       {
           matriz[i][2] = coeficiente;
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
       if(matriz[i][1] != 0 && matriz[i][3] != 0)
       {
           x << matriz[i][0] << " " << matriz[i][1] << matriz[i][2] << " " << matriz[i][3] << "\n";
       }
       respuesta += x.str();
   }
   return respuesta;
}

void Polinomio::Agregar(int coeficienteX, int exponenteX, int coeficienteY, int exponenteY)
{
    for(int i=0; i<10; i++){
        if(matriz[i][1] == 0 && matriz[i][3] == 0)
        {
            matriz[i][0] = coeficienteX;
            matriz[i][2] = coeficienteY;
            matriz[i][1] = exponenteX;
            matriz[i][3] = exponenteY;
        }
    }
}

void Polinomio::Modificar(int coeficienteX, int exponenteX, int coeficienteY, int exponenteY)
{
   for(int i=0; i<10; i++){
       if(matriz[i][1] == exponenteX && matriz[i][3] == exponenteY)
       {
           matriz[i][0] = coeficienteX;
           matriz[i][2] = coeficienteY;
       }
   }
}

int Polinomio::GetCoeficienteX(int expo)
{
   int r = 0;
   for(int i = 0; i < 10; i++)
   {
       if(matriz[i][1] == expo){
           r = matriz[i][0];
           i = 10;
       }
   }
   return r;
}

int Polinomio::GetCoeficienteY(int expo)
{
   int r = 0;
   for(int i = 0; i < 10; i++)
   {
       if(matriz[i][3] == expo){
           r = matriz[i][2];
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
       if(matriz[i][2] == coefi){
           r = matriz[i][3];
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
           x << matriz[i][0] << "x" << matriz[i][1] << " " << matriz[i][2] << "y" << matriz[i][3] << "+";
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
       int a = matriz[i][3];
       if(resp < a)
       {
           resp = a;
       }
   }
   return resp;
}

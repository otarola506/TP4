#include "polinomio.h"
#include "algoritmog.h"

int main()
{
    Polinomio v ("2x2y3+3x3y9+4x4y8");
    v.SepararMonomio();
    //cout << v.Imprimir();
    v.Derivar();
    cout << v.ImprimirDerivada();
    return 0;
}
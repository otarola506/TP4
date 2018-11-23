#include "lista.h" 

void Lista::Insertar(int x) {
    if (cabeza==NULL){
        cabeza= new Nodo(x); 
    } else {
        Nodo *n= new Nodo(x) ;
        n->SetSiguiente(cabeza) ;
        cabeza= n ;
    }
    cNodos++;
};
void Lista::Modificar(int posicion,int dato){
    if(posicion<=cNodos){
        Nodo *n=cabeza;
        for(int i=0;i<posicion;i++){
            n=n->GetSiguiente();
        }
        n->SetDato(dato);
    }
}

void Lista::Imprimir() {
    Nodo *n= cabeza ;
    while (n!=NULL) {
        cout << n->GetDato() << ":"  ;
        n= n->GetSiguiente() ;
    }
};

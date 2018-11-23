#ifndef AGENTEVIAJERO_H
#define AGENTEVIAJERO_H
class AgenteViajero{

    int datos[4][4];
    public:
    AgenteViajero(){
        datos[0][0]=-1;
        datos[0][1]=-1;
        datos[0][2]=-1;
        datos[0][3]=5;
        datos[0][4]=12;
        datos[1][0]=10;
        datos[1][1]=-1;
        datos[1][2]=-1;
        datos[1][3]=-1;
        datos[1][4]=-1;
        datos[2][0]=-1;
        datos[2][1]=4;
        datos[2][2]=-1;
        datos[2][3]=4;
        datos[2][4]=-1;
        datos[3][0]=-1;
        datos[3][1]=3;
        datos[3][2]=2;
        datos[3][3]=-1;
        datos[3][4]=7;
        datos[4][0]=-1;
        datos[4][1]=-1;
        datos[4][2]=6;
        datos[4][3]=-1;
        datos[4][4]=-1;
    }

    int getDatos(int ciudadPartida, int ciudadLlegada){
        return datos[ciudadPartida][ciudadLlegada];
    }
}
#endif // AGENTEVIAJERO_H

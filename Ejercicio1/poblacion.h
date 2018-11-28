#ifndef POBLACION_H
#define POBLACION_H
class Poblacion{
    int x;
    int y;
    int z;
    int apti;
public:
    Poblacion(){}
    Poblacion(int a, int b, int d){
        x=a;
        y=b;
        z = d;
        apti=-1;
    }
    void setX(int a){
        x=a;
    }
    void setY(int b){
        y=b;
    }
    void setApti(int c){
        apti=c;
    }
    void setZ(int d){
        z=d;
    }
    int getZ(){
       return z;
    }
    int getApti(){
       return apti;
    }
    int getX(){
       return x;
    }
    int getY(){
       return y;
    }
};
#endif // POBLACION_H

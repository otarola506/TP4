#ifndef POBLACION_H
#define POBLACION_H
class Poblacion{
    int x;
    int y;
    int apti;
public:
    Poblacion(){}
    Poblacion(int a, int b){
        x=a;
        y=b;
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

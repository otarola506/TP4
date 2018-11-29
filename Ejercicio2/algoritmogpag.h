#ifndef ALGORITMOGPAG_H
#define ALGORITMOGPAG_H
#include "algoritmogpag_global.h"
#include "agenteviajero.h"
#include <iostream>
#include <time.h>
using namespace std;
class  ALGORITMOGPAGSHARED_EXPORT AlgoritmoG{

    int generadorX;
    int generadorY;
    int laPoblacion[130][7] ;
    AgenteViajero agente1;
    public:

    AlgoritmoG(){
        for(int i=0;i<130;i++){
            for(int s=0;s<7;s++){
                laPoblacion[i][s]=-1;
            }
        }

        for(int i=0;i<101;i++){
            generadorX = rand() % 5;
            laPoblacion[i][0]=0;
            laPoblacion[i][5]=0;
            for(int s=0;s<4;s++){
                while(laPoblacion[i][0]==generadorX ||laPoblacion[i][1]==generadorX||laPoblacion[i][2]==generadorX ||laPoblacion[i][3]==generadorX||laPoblacion[i][4]==generadorX){
                    generadorX = rand() % 5;

                }
                laPoblacion[i][s+1]=generadorX;
            }
        }

      for(int i=0;i<10000;i++){
         cruzar();
         mutar();
         aptitud();
         seleccionar();
      }
      int k=0;
      while(laPoblacion[k][6]==-1){
          k++;
      }
      for(int i=0;i<6;i++){
          cout<<laPoblacion[k][i]<<endl;
      }
       cout<<laPoblacion[k][6]<<endl;
    }


    void cruzar(){
        int generadorW;
        for(int i=0;i<30;i++){
           generadorX = rand() % 100+1;
           generadorY= rand() % 100+1;
           for(int r=0;r<6;r++){
               if(r<3){
                   laPoblacion[i+100][r]=laPoblacion[generadorX][r];
               }else{
                   if(laPoblacion[i+100][1]!=laPoblacion[generadorY][r]&&laPoblacion[i+100][2]!=laPoblacion[generadorY][r]){
                       laPoblacion[i+100][r]=laPoblacion[generadorY][r];
                   }else{
                       generadorW=laPoblacion[generadorY][r];
                       while(laPoblacion[i+100][r-2]==generadorW ||laPoblacion[i+100][r-3]==generadorW||laPoblacion[i+100][r-1]==generadorW){
                           generadorW = rand() % 4+1;
                       }
                        laPoblacion[i+100][r]=generadorW;
                   }
               }
           }
        }
    }

    void mutar(){
        int generadorEm;
        for(int i=0;i<26;i++){
            generadorX=rand()% 130;
            generadorY=rand()% 4+1;
            generadorEm=rand()% 4+1;
            int temp=laPoblacion[generadorX][generadorEm];
            int j=0;
            laPoblacion[generadorX][generadorEm]=generadorY;
            /*while(laPoblacion[generadorX][generadorEm]!=laPoblacion[generadorX][j]){
                j++;
            }
            laPoblacion[generadorX][j]=temp;
*/

        }

    }
    void aptitud(){
        int temporal=0;
        for(int i=0;i<130;i++){
            temporal=0;
            for(int s=0;s<5;s++){
                if(agente1.getDatos(laPoblacion[i][s],laPoblacion[i][s+1])!=-1){
                    temporal+=agente1.getDatos(laPoblacion[i][s],laPoblacion[i][s+1]);

                }else{
                    temporal=-1;
                    s=5;
                }

            }

            laPoblacion[i][6]=temporal;

        }
    }

    void ordenar(){
        int temporal[7];
        for(int i=0;i<130;i++){
            for(int j=i+1;j<130;j++){
                if(laPoblacion[i][6]<laPoblacion[j][6]){
                    for(int s=0;s<7;s++){
                        temporal[s]=laPoblacion[i][s];
                        laPoblacion[i][s]=laPoblacion[j][s];
                        laPoblacion[j][s]=temporal[s];
                     }
                }
            }
        }
    }

    void seleccionar(){
        ordenar();
        int temp=0;
        for(int i=0;i<85;i++){

        }
        for(int i=0;i<15;i++){
            for(int s =0; s<6;s++){
                while(laPoblacion[130-temp][6]<-1){
                    temp++;
                }
                laPoblacion[i+85][s]=laPoblacion[130-(temp+i)][s];
             }



        }

    }
};
#endif // ALGORITMOGPAG_H

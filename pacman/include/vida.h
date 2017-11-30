#ifndef VIDA_H
#define VIDA_H
#include <iostream>
#include <stack>
#include <cstdlib>
#include "escenario.h"
#include <allegro.h>

using namespace std;

class vida
{
    public:
        int cont=3;
        stack<char>s;
        BITMAP *vida_;

        vida(){
            for (int i=0;i<=2;i++)
                s.push(i);

            vida_=load_bitmap("vida.bmp",NULL);}

        void agregar(){
            s.push(1);
            cont=cont+1;}

        void secar(){
            if (!s.empty()){
                s.top();
                s.pop();
                cont=cont-1;}}

        template <class E>
        void dibujar_vida(E escenario1){
            if (cont==3){
                for (int filas_m1=0; filas_m1< 17; filas_m1++){
                for(int col_m1=0; col_m1<40; col_m1++){
                    if (escenario1.mapa_1[filas_m1][col_m1]=='P')
                        draw_sprite(escenario1.buffer,vida_,col_m1*30,filas_m1*30);
                }
            }

            }
        }
};

#endif // VIDA_H

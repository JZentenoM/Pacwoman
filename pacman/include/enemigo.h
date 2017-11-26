#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "escenario.h"
#include "entidad.h"



#include <allegro.h>
#include <cstdlib>

class enemigo : public entidad
{
    public:
        BITMAP *enemigo_mb;
        BITMAP *enemigo_;

        enemigo(){
            posX=0;
            posY=0;
            direccion=0;
            enemigo_ = create_bitmap (20,20);
            enemigo_mb = load_bitmap("enemigo.bmp",NULL);
            }

        void setPosicion(int x, int y){
            posX=x;
            posY=y;}

        void dibujar_fantasma(escenario escenario1){
            blit(enemigo_mb, enemigo_,0,0,0,0,20,20);
            draw_sprite(escenario1.escenario_, enemigo_, posX, posY);}



        void movimientoFantasma(escenario escenario1){

            if (direccion==0){
                if(escenario1.mapa_1[posY/20][(posX-20)/20] != 'X')
                   posX-=20;
                else
                    direccion = rand()% 2 + 2;}
            if (direccion==1){
                if(escenario1.mapa_1[posY/20][(posX+20)/20]!= 'X')
                    posX+=20;
                else
                    direccion = rand()% 2 + 2 ;}
            if (direccion==2){
                if(escenario1.mapa_1[(posY-20)/20][(posX)/20]!= 'X')
                    posY-=20;
                else
                    direccion = rand()% 2 + 0;}
            if (direccion==3){
                if(escenario1.mapa_1[(posY+20)/20][(posX)/20]!= 'X')
                    posY+=20;
                else
                    direccion = rand()% 2 + 0;}
            if(posX<=-20)
                posX=1000;
            else if (posX>=1000)
                posX=-20;}


};



#endif // ENEMIGO_H

#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "entidad.h"
#include "escenario.h"
#include "claseallegro.h"
#include "personaje.h"
#include <allegro.h>
#include <cstdlib>

class enemigo : public entidad
{
    public:
        BITMAP *enemigo_mb;
        BITMAP *enemigo_;
        int posX, posY, fdireccion;



        enemigo(){
            posX=0;
            posY=0;
            fdireccion=0;
            enemigo_ = create_bitmap (20,20);
            enemigo_mb = load_bitmap("enemigo.bmp",NULL);
            }

        void setPosicion(int x, int y){
            posX=x;
            posY=y;}

        void dibujar_fantasma(escenario escenario1){
            blit(enemigo_mb, enemigo_,0,0,0,0,20,20);
            draw_sprite(escenario1.escenario_, enemigo_, posX, posY);}

        void choqueFantasma(personaje pacman1,escenario escenario1,claseallegro juego){
            if ((pacman1.posY == posY && pacman1.posX == posX)|| (pacman1.posY==(posY-30) && pacman.posX ==(posX-30))){
                for (int j=0; j<=5; j++){
                    clear(pacman1.pacman);
                    clear(escenario1.escenario_);
                    escenario1.dibujar_mapa();
                        blit(pacman1.pacman_mb,pacman1.muerte,j*30,0,0,0,30,30);
                        draw_sprite(escenario1.escenario_,pacman1.muerte,pacman1.posX, pacman1.posY);
                        juego.pantalla();
                        rest(90);}
                    pacman1.posX=30*10;
                    pacman1.posY=30*12;
                    pacman1.direccion=4;}}

        void movimientoFantasma(escenario escenario1){

            if (fdireccion==0){
                if(escenario1.mapa_1[posY/20][(posX-20)/20] != 'X')
                   posX-=20;
                else
                    fdireccion = rand()% 2 + 2;}
            if (fdireccion==1){
                if(escenario1.mapa_1[posY/20][(posX+20)/20]!= 'X')
                    posX+=20;
                else
                    fdireccion = rand()% 2 + 2 ;}
            if (fdireccion==2){
                if(escenario1.mapa_1[(posY-20)/20][(posX)/20]!= 'X')
                    posY-=20;
                else
                    fdireccion = rand()% 2 + 0;}
            if (fdireccion==3){
                if(escenario1.mapa_1[(posY+20)/20][(posX)/20]!= 'X')
                    posY+=20;
                else
                    fdireccion = rand()% 2 + 0;}
            if(posX<=-20)
                posX=1000;
            else if (posX>=1000)
                posX=-20;}

};

#endif // ENEMIGO_H

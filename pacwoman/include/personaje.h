#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "entidad.h"
#include "escenario.h"
#include "claseallegro.h"
#include "enemigo.h"


class personaje : public entidad
{
    public:
       BITMAP *pacman_mb;
        BITMAP *pacman;

        personaje(){
        posX = 0;
        posY = 0;
        direccion = 4;
        pacman_mb = load_bitmap("pacman.bmp",NULL);
        pacman = create_bitmap(30,30);

        }

        void setPosicion(int x, int y){
            this->posX=x;
            this->posY=y;
        }

        void dibujarPersonaje(escenario escenario1){
            blit(pacman_mb, pacman, direccion*30,0,0,0,30,30);
            draw_sprite(escenario1.escenario_, pacman,posY, posX);

        }


        void movimiento( escenario escenario1){


            if (key[KEY_LEFT]) direccion=2;
            else if (key[KEY_RIGHT])direccion=0;
            else if (key[KEY_UP]) direccion=4;
            else if (key[KEY_DOWN]) direccion=3;

            if(direccion==0) {
                if (escenario1.mapa_1[posY/30][(posX+30)/30] != 'X')
                    posX +=30;
                else
                    direccion=1;
            }
            if(direccion==2) {
                if (escenario1.mapa_1[posY/30][(posY-30)/30] != 'X')
                    posX -=30;
                else
                    direccion=1;
                }
            if (direccion==4) {
                if (escenario1.mapa_1[(posY-30)/30][posX/30]!= 'X')
                    posY -=30;
                else
                    direccion=1;
                    }
            if(direccion==3) {
                 if (escenario1.mapa_1[(posY+30)/30][posY/30]!= 'X')
                    posY +=30;
                else
                    direccion=1;
            }
            if(escenario1.mapa_1[posY/30][posX/30]!= 'o')
                   escenario1.mapa_1[posY][posX]= ' ';

        }



};


#endif // PERSONAJE_H

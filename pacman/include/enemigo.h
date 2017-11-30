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
        BITMAP *enemigo2_mb;
        BITMAP *enemigo3_mb;
        BITMAP *enemigo4_mb;

        BITMAP *enemigo_;

        enemigo(){
            posX=0;
            posY=0;
            direccion=2;
            enemigo_ = create_bitmap (30,30);
            enemigo_mb = load_bitmap("enemigo.bmp",NULL);
            enemigo2_mb = load_bitmap("enemigo1.bmp",NULL);
            enemigo3_mb = load_bitmap("enemigo2.bmp",NULL);
            enemigo4_mb = load_bitmap("enemigo3.bmp",NULL);
            }

        void setPosicion(int x, int y){
            posX=x;
            posY=y;
        }


        void dibujar_fantasma(escenario escenario1,int colorFantasma){
            if (colorFantasma==1)
            blit(enemigo_mb, enemigo_,0,0,0,0,30,30);
            if (colorFantasma==2)
            blit(enemigo2_mb, enemigo_,0,0,0,0,30,30);
            if (colorFantasma==3)
            blit(enemigo3_mb, enemigo_,0,0,0,0,30,30);
            if (colorFantasma==4)
            blit(enemigo4_mb, enemigo_,0,0,0,0,30,30);

            draw_sprite(escenario1.buffer, enemigo_, posX, posY);
        }



        void movimientoFantasma(escenario e1, int numMapa){

            int d0,d1,d2,d3;
        //PARA EL MAPA 1
            if (numMapa==1){
                d0=e1.mapa_1[posY/30][(posX-30)/30];
                d1=e1.mapa_1[posY/30][(posX+30)/30];
                d2=e1.mapa_1[(posY-30)/30][posX/30];
                d3=e1.mapa_1[(posY+30)/30][posX/30];}

        //PARA EL MAPA 2
            else if (numMapa==2){
                d0=e1.mapa_1[posY/30][(posX-30)/30];
                d1=e1.mapa_1[posY/30][(posX+30)/30];
                d2=e1.mapa_1[(posY-30)/30][posX/30];
                d3=e1.mapa_1[(posY+30)/30][posX/30];}

            if (direccion==0){
                if((d0 != 'Z') && (d0 != 'X')&& (d0 != 'C')&& (d0 != 'V') &&
                   (d0 != 'B') && (d0 != 'N') && (d0 != 'M') && (d0 != 'A') &&
                   (d0 != 'S')&& (d0 != 'D')&& (d0 != 'F')&& (d0 != 'G')&& (d0 != 'H') &&
                   (d0 != 'W')&& (d0 != 'Q')&& (d0 != 'L')&& (d0 != 'K')&& (d0 != 'J') &&
                   (d0 != 'E')&& (d0 != 'R'))
                   posX-=30;
                else
                    direccion = rand()% 2 + 2;
            }

            if (direccion==1){
                if((d1 != 'Z') && (d1 != 'X')&& (d1 != 'C')&& (d1 != 'V') &&
                   (d1 != 'B') && (d1 != 'N') && (d1 != 'M') && (d1 != 'A') &&
                   (d1 != 'S')&& (d1 != 'D')&& (d1 != 'F')&& (d1 != 'G')&& (d1 != 'H') &&
                   (d1 != 'W')&& (d1 != 'Q')&& (d1!= 'L')&& (d1 != 'K')&& (d1 != 'J') &&
                   (d1 != 'E')&& (d1 != 'R'))
                    posX+=30;
                else
                    direccion = rand()% 2 + 2 ;
            }

            if (direccion==2){
                if((d2 != 'Z') && (d2 != 'X')&& (d2 != 'C')&& (d2 != 'V') &&
                   (d2 != 'B') && (d2 != 'N') && (d2 != 'M') && (d2 != 'A') &&
                   (d2 != 'S')&& (d2 != 'D')&& (d2 != 'F')&& (d2 != 'G')&& (d2 != 'H') &&
                   (d2 != 'W')&& (d2 != 'Q')&& (d2 != 'L')&& (d2 != 'K')&& (d2 != 'J') &&
                   (d2 != 'E')&& (d2 != 'R'))
                    posY-=30;
                else
                    direccion = rand()% 2 + 0;
            }

            if (direccion==3){
                if((d3 != 'Z') && (d3 != 'X')&& (d3 != 'C')&& (d3 != 'V') &&
                   (d3 != 'B') && (d3 != 'N') && (d3 != 'M') && (d3 != 'A') &&
                   (d3 != 'S')&& (d3 != 'D')&& (d3 != 'F')&& (d3 != 'G')&& (d3 != 'H') &&
                   (d3 != 'W')&& (d3 != 'Q')&& (d3 != 'L')&& (d3 != 'K')&& (d3 != 'J') &&
                   (d3 != 'E')&& (d3 != 'R'))
                    posY+=30;
                else
                    direccion = rand()% 2 + 0;
            }

            //ATRAVEZAR ESCENARIO

            if(posX<=-30)
                posX=1170;
            else if (posX>=1170)
                posX=-30;
            if (posY<=-30)
                posY=510;
            else if (posY>=510)
                posY=-30;}



};



#endif // ENEMIGO_H

#ifndef POWERUP_H
#define POWERUP_H
#include <allegro.h>

#include "escenario.h"
#include "personaje.h"



class powerup
{
    public:
        BITMAP *coin;
        BITMAP *coin_mb;
        BITMAP *poder_mb;
        BITMAP *poder;



       powerup(){
            coin = create_bitmap (30,30);
            poder = create_bitmap (30,30);
            coin_mb = load_bitmap("coin.bmp",NULL);
            poder_mb = load_bitmap("poder.bmp",NULL);
        }


        void dibujar_comida(escenario escenario1, int power){
           blit(poder_mb, poder,0,0,0,0,30,30);
           blit(coin_mb, coin,0,0,0,0,30,30);

            int filas_m1, col_m1;
            for (filas_m1=0; filas_m1< 17; filas_m1++){
                for(col_m1=0; col_m1<40; col_m1++){

                    if (power==1){
                        if (escenario1.mapa_1[filas_m1][col_m1]=='o'){
                            draw_sprite(escenario1.escenario_,coin,col_m1*30,filas_m1*30);}
                        if ((escenario1.mapa_1[filas_m1][col_m1]=='P')){
                            draw_sprite(escenario1.escenario_,poder,col_m1*30,filas_m1*30);}
                    }

                    else if (power==2){
                        if (escenario1.mapa_2[filas_m1][col_m1]=='o'){
                            draw_sprite(escenario1.escenario_,coin,col_m1*30,filas_m1*30);}
                        if ((escenario1.mapa_2[filas_m1][col_m1]=='P')){
                            draw_sprite(escenario1.escenario_,poder,col_m1*30,filas_m1*30);}
                    }
                }
            }
        }





};

#endif // POWERUP_H

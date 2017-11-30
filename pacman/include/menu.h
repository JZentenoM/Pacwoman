#ifndef MENU_H
#define MENU_H
#include <allegro.h>
#include "escenario.h"

class menu
{
    public:
        BITMAP *buffer;
        BITMAP *menu_;
        BITMAP *menu_2;
        int posX;
        int posY;


        menu(){
        menu_ = load_bitmap("menu.bmp",NULL);
        menu_2= load_bitmap("menu3.bmp",NULL);
        buffer = create_bitmap(1200,510);

        }

        void dibujarMenu(){
            int color=0;
            int y=0;
            int contador = 0;
            bool salida = false;
            bool cargando = false;

            while (!salida){
                if(color < 25){
                    draw_sprite(buffer, menu_,0, 0);
             }


        }}







};
#endif // MENU_H

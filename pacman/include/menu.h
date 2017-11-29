#ifndef MENU_H
#define MENU_H
#include <allegro.h>
#include "escenario.h"

class menu
{
    public:
        BITMAP *menu_mb;
        BITMAP *menu_;
        int posX;
        int posY;


        menu(){
        posX = 10;
        posY = 10;
        menu_mb = load_bitmap("pacman.bmp",NULL);
        menu_ = create_bitmap(30,30);

        }

        void dibujarMenu(escenario escenario1){
            blit(menu_mb,menu_,1*30,0,0,0,30,30);
            draw_sprite(escenario1.escenario_, menu_,0, 0);
        }





};
#endif // MENU_H

#ifndef MENU_H
#define MENU_H
#include <allegro.h>
#include "escenario.h"
#include <iostream>

using namespace std;

class menu
{
    public:
        BITMAP *buffer;
        BITMAP *menu_;
        BITMAP *jugadores;

        menu(){
        menu_ = load_bitmap("menu.bmp",NULL);
        jugadores = load_bitmap("teclas.bmp",NULL);
        buffer = create_bitmap(1200,510);

        }

        void dibujarMenu(int numMenu){
            if (numMenu==1)
                    blit(menu_,buffer,0,0,0,0,1200,510);
            else
                    blit(menu_,buffer,0,510,0,0,1200,510);


        }



};
#endif // MENU_H

#ifndef CLASEALLEGRO_H
#define CLASEALLEGRO_H
#include <allegro.h>
#include <cstdlib>

#include "personaje.h"
#include "entidad.h"
#include "escenario.h"

class claseallegro
{

    public:
        claseallegro(){
            allegro_init();
            install_keyboard();
            set_color_depth(32);
            set_gfx_mode(GFX_AUTODETECT_WINDOWED,900,630,0,0);
        }

        void pantalla(escenario escenario1){
            blit(escenario1.escenario_, screen, 0,0,0,0,900,700);
        }


};

#endif // CLASEALLEGRO_H

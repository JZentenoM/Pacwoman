#ifndef ESCENARIO_H
#define ESCENARIO_H
#include <allegro.h>

#define Filas 33
#define Columnas 51
using namespace std;

class escenario
{
    public:
        BITMAP *escenario_;
        BITMAP *roca;


        char mapa_1[Filas][Columnas]={

                "                                                  ",
                "                                                  ",
                "                                                  ",
                "                                                  ",
                "                                                  ",
                " XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ",
                " X                                              X ",
                " X                                              X ",
                " X                                              X ",
                " X                                              X ",
                " X                                              X ",
                " X                                              X ",
                " X                 X                            X ",
                " X                 X                            X ",
                " X                 X                            X ",
                " X                                              X ",
                " X    XXXX                                      X ",
                " X                                              X ",
                " X                                              X ",
                " X                                              X ",
                " X                                              X ",
                " X oooooooooooooooooooooooooooooooooooooooooooo X ",
                " X                                              X ",
                " X                                              X ",
                " X                                              X ",
                " X                                              X ",
                " X                                              X ",
                " X                                              X ",
                " X X                                            X ",
                " X X                                            X ",
                " XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ",
};

        escenario(){
        escenario_ = create_bitmap (1000 ,640);
        roca= load_bitmap("roca.bmp",NULL);

        }

        void dibujar_mapa(){
            int filas_m1, col_m1;
            for (filas_m1=0; filas_m1< Filas; filas_m1++){
                for(col_m1=0; col_m1<Columnas; col_m1++){
                    if (mapa_1[filas_m1][col_m1]=='X')
                        draw_sprite(escenario_,roca,col_m1*20,filas_m1*20);
                    }}}


};

#endif // ESCENARIO_H

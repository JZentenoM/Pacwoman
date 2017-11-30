#include <allegro.h>
#include <cstdlib>

#include "personaje.h"
#include "entidad.h"
#include "claseallegro.h"
#include "escenario.h"
#include "enemigo.h"
#include "powerup.h"
#include "menu.h"
#include "vida.h"

int main()
{
    int score=0;
    bool gameover = false;

 // EJECUTADOR DEL CODIGO POR DEFECTO DE ALLEGRO Y CREADOR DE MAPA
    claseallegro juego;
    escenario mapa1;

 // MENÚ
    menu menu1;
    while (!key[KEY_ENTER]){
            clear(mapa1.buffer);
            menu1.dibujarMenu(1);
            juego.pantalla(menu1);

    }


 // SELECTOR DE NUMERO DE JUGADORES
    int inicio = false;
    int numPlayer = 0;

    while (!inicio){
        clear(mapa1.buffer);
        menu1.dibujarMenu(2);
        juego.pantalla(menu1);



        if (key[KEY_1]){
            numPlayer = 1;
            inicio=true;}

        else if (key[KEY_2]){
            numPlayer = 2;
            inicio=true;}

        else if (key[KEY_3]){
            numPlayer = 3;
            inicio=true;}
    }

 // DECLARACION DE NUMERO DE JUGADORES (MAX 3)
    personaje *pacman = new personaje[numPlayer];

    for (int i=0; i<numPlayer; i++)
        pacman[i].setPosicion(30*(19+i),30*12);

 // DECLARACION DEL NÚMERO DE ENEMIGOS

    enemigo *fantasma = new enemigo[4];

    for (int i=0; i<4; i++)
        fantasma[i].setPosicion(30*19,30*(6+i));

 // COMIDA
    powerup comida1;

  // VIDA
    vida vida_;


 //BÚCLE DEL JUEGO

    while((!key[KEY_ESC]) || gameover){

 // DIBUJAR VIDA
        vida_.dibujar_vida(mapa1);

 // MOVIMIENTO DEL PACMAN
        for (int i=0; i<numPlayer; i++)
            pacman[i].movimiento(mapa1,i,1);

 // FUNCION COMER DE PACMAN
        for (int i=0; i<numPlayer; i++){
            for (int filas_m1=0; filas_m1< 17; filas_m1++){
                    for(int col_m1=0; col_m1<40; col_m1++){
                        if (mapa1.mapa_1[filas_m1][col_m1]=='o'){
                            if (pacman[i].posY/30==filas_m1 && pacman[i].posX/30 == col_m1){
                                mapa1.mapa_1[filas_m1][col_m1]=' ';
                                score=score+1;}


                        }
                    }
            }
        }


        clear(mapa1.buffer);

 // IMPRESOR DE COMIDA Y MAPA
        comida1.dibujar_comida(mapa1,1);
        mapa1.dibujar_mapa();


 // IMPRESOR DE PERSONAJES Y FUNCION DE CHOQUE
        int posicionVida=20;
        for (int f=0; f<4; f++){
            for (int i=0; i<numPlayer; i++){
                pacman[i].dibujarPersonaje(mapa1,true,i+1);
                pacman[i].choqueFantasma(fantasma[f],mapa1,juego);
                if (pacman[i].choque){
                        mapa1.mapa_1[1][posicionVida]=' ';
                        posicionVida--;
                        pacman[i].choque=false;
                }
            }
        }


 // IMPRESOR DE ENEMIGO Y FUNCION DE MOVIMIENTO DE LOS MISMOS
        for (int f=0; f<4; f++){
            fantasma[f].dibujar_fantasma(mapa1,(f+1));
            fantasma[f].movimientoFantasma(mapa1,1);}


        juego.pantalla(mapa1);
        rest(90);

// LIMPIADOR DEL MB DE PACMAN
        for (int i=0; i<numPlayer; i++)
            clear(pacman[i].pacman);

// IMPRESOR DEL SEGUNDO MOVIMIENTO DE PACMAN
        for (int f=0; f<4; f++){
            for (int i=0; i<numPlayer; i++){
                pacman[i].dibujarPersonaje(mapa1, false,i+1);
                pacman[i].choqueFantasma(fantasma[f],mapa1,juego);}}


        juego.pantalla(mapa1);
        rest(50);
    }

    cout << "*************************************************"<<endl;
    if (numPlayer==1)
    cout << "Felicitaciones Jugador obtuviste " << score << " puntos"<< endl << endl;
    else
    cout << "Felicitaciones Jugadores obtuvieron " << score << " puntos"<< endl << endl;
    cout << "*************************************************"<< endl;
    cout << "GRACIAS POR JUGAR :D" << endl;
    return 0;
}
END_OF_MAIN();

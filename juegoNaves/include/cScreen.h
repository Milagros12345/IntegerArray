#ifndef CSCREEN_H
#define CSCREEN_H
#define numero 5
#include "juego.h"
#include<SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
using namespace sf;
class cScreen
{
    public:
        juego correr;
        sf::RenderWindow ventana;
        bool inicio;
        int tiem;
        bool inicializa();

        Texture fondo1;
        Texture fondo2;
        Sprite fon1;
        Sprite fon2;
        cScreen();
        void evento();
        void dibujarSprite();
        void moveUp();
        void moveDown();
        int GetPressedItem(){return sel;}
        void accion();
    private:
        int sel;
        Text opcion[numero];
        Font fuente1;
        Font fuente2;
        SoundBuffer buffer;
        Sound s;

};

#endif // CSCREEN_H

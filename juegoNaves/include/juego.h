#ifndef JUEGO_H
#define JUEGO_H
#include <vector>
#include "nave.h"
#include "bala.h"
#include "enemies.h"
#include "score.h"
#include <list>
#include<SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
using namespace std;
using namespace sf;
class juego
{
    public:
        int speed;
        Time delta;

        juego();
        void jugar();
        void iniciar();
        void dibujar();
    private:
        RenderWindow ventana1;
        sf::SoundBuffer buffer;
        Sound sonido;
        Texture textura1,textura2;
        Sprite fondo;
        nave mi_nave;
        score *puntos;
        enemies *enemic;
        vector<bala> proyectiles;
        vector<enemies> enemigo;
        Clock clock;
        bool disparo;
        int spawn;
        int shootTimer;


};

#endif // JUEGO_H

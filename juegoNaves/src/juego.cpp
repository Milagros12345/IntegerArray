#include "juego.h"
#include "nave.h"
#include "bala.h"
#include "enemies.h"
#include<SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include"SFML\System.hpp"
#include<cstdlib>
#include <iostream>
#include <time.h>
#include <vector>
#define ancho 850
#define alto 854
using namespace sf;
using namespace std;
juego::juego(){}
void juego::iniciar(){
    srand(time(NULL));
    ventana1.create(VideoMode(ancho, alto), "mi juego");
    ventana1.setFramerateLimit(60);
    if(buffer.loadFromFile("dis.wav")){
        system(" no se pudo cargar el audio");
    }

    sonido.setBuffer(buffer);

    if(!textura1.loadFromFile("fig2.jpg")){
        system("echo no se pudo cargar la imagen fondo");
        //return EXIT_FAILURE;
    }
    //inicio de la nave
    fondo.setTexture(textura1);
    textura2.loadFromFile("nave.jpg");
    mi_nave.nave2(Vector2f(50,40));
    mi_nave.setPosition(300,800);
    //tipo bala
    bala ball(Vector2f(10.0f,20.0f));
    proyectiles.push_back(ball);
    //enemigo inicializandi
    enemic=new enemies(Vector2f(40,40));
    enemigo.push_back(*enemic);
    spawn=0;
    disparo=false;
    shootTimer=0;
    puntos=new score;
    jugar();
}
void juego::jugar(){
    bala ball(Vector2f(10.0f,20.0f));
    while (ventana1.isOpen())
    {
        sf::Event event;
        while (ventana1.pollEvent(event))
        {
            if (event.type == Event::Closed)
                ventana1.close();}
                if(Keyboard::isKeyPressed(Keyboard::Up)&& mi_nave.posy()>500)
                {
                    mi_nave.setPosition(mi_nave.posx(),mi_nave.posy()-2);
                }
                else if(Keyboard::isKeyPressed(Keyboard::Down)&& mi_nave.posy()<800)
                {
                    mi_nave.setPosition(mi_nave.posx(),mi_nave.posy()+2);
                }
                else if(Keyboard::isKeyPressed(Keyboard::Left) && mi_nave.posx()>4)
                {
                    mi_nave.setPosition(mi_nave.posx()-10,mi_nave.posy());
                }
                else if(Keyboard::isKeyPressed(Keyboard::Right) && mi_nave.posx()<790)
                {
                    mi_nave.setPosition(mi_nave.posx()+10,mi_nave.posy());
                }
                else if(Keyboard::isKeyPressed(Keyboard::Space) && shootTimer>=5)
                {
                    disparo=true;
                }
                //preparando bala
                if(shootTimer<5)
                    shootTimer++;
                if(disparo){
                    sonido.play();
                    ball.setPos(Vector2f(mi_nave.posx()+20,mi_nave.posy()));
                    proyectiles.push_back(ball);
                    shootTimer = 0;
                    disparo=false;
                }

                for (size_t i = 0; i < proyectiles.size(); i++)
                {
                    proyectiles[i].fire(-10.f);
                    if(proyectiles[i].posY() <0 || proyectiles[i].posX()>ancho || proyectiles[i].posY()<0 || proyectiles[i].posY()>alto)
                        proyectiles.erase(proyectiles.begin() + i);
                }
                //preparando enemigo
                if(spawn<20) spawn++;
                if(spawn>=20)
                {
                    enemic->setPosition1((rand()%int(ventana1.getSize().x - enemic->getSizex())),0.f);
                    enemigo.push_back(*enemic);
                    spawn=0;
                }
                for (size_t i = 0; i < enemigo.size(); i++)
                {
                    enemigo[i].mover(Vector2f(0.f,5.f));

                    if (enemigo[i].posy()>ventana1.getSize().y)
                        enemigo.erase(enemigo.begin() + i);
                }
                if (!enemigo.empty() && !proyectiles.empty())
                    {
                        for (size_t i = 0; i < proyectiles.size(); i++)
                        {
                            for (size_t k = 0; k < enemigo.size(); k++)
                            {
                                if ((proyectiles[i].posY())<(enemigo[k].getSizey()+enemigo[k].posy()))
                                { cout<<"hubo colicion ";/*
                                    proyectiles.erase(proyectiles.begin() + i);
                                    enemigo.erase(enemigo.begin() + k);*/
                                    puntos->puntoPlayer+=10;
                                    proyectiles[i].setPos(Vector2f(20000000000,2000000000000));
                                    enemigo[k].setPosition(2100000000,1000000000);
                                    break;
                                }
                            }
                        }
                    }

       dibujar();
    }
}

void juego::dibujar(){
    ventana1.clear();
    ventana1.draw(fondo);
    puntos->show(ventana1);
    mi_nave.dibujar(ventana1);
    for (size_t i = 0; i < enemigo.size(); i++)
		{
			enemigo[i].dibuja(ventana1);
		}
    for (size_t i = 0; i < proyectiles.size(); i++)
		{
			proyectiles[i].draw(ventana1);
		}
    ventana1.display();
}

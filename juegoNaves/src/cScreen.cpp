#include "cScreen.h"
#include "juego.h"
#include<SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <iostream>
#include <sstream>
#define ancho 1200
#define alto 630
#define titulo "mi videojuego "

cScreen::cScreen(){ }
bool cScreen::inicializa(){
    if(!fuente1.loadFromFile("ACafe.ttf")){
        return false;
    }
    if(!fuente2.loadFromFile("ACafe.ttf")){
        return false;
    }
    if(!fondo1.loadFromFile("opciones.jpg")){
        return false;
    }
    if(buffer.loadFromFile("clic.wav")){
        system(" no se pudo cargar el audio");
    }

    s.setBuffer(buffer);
    ventana.create(sf::VideoMode(ancho,alto),titulo);
    ventana.setFramerateLimit(50);
    fon1.setTexture(fondo1);
    opcion[0].setFont(fuente1);
    opcion[1].setFont(fuente1);
    opcion[2].setFont(fuente1);
    opcion[3].setFont(fuente2);
    opcion[4].setFont(fuente2);

    opcion[0].setString("PLAY");
    opcion[0].setCharacterSize(40);
    opcion[0].setPosition(520,190);
    opcion[0].setColor(sf::Color(255,180,255));


    opcion[1].setString("SCORES");
    opcion[1].setCharacterSize(40);
    opcion[1].setPosition(463,305);
    opcion[1].setColor(sf::Color(100,0,50));

    opcion[2].setString("MINIJUEGO");
    opcion[2].setCharacterSize(40);
    opcion[2].setPosition(450,423);
    opcion[2].setColor(sf::Color(100,0,50));

    opcion[3].setString("CREDITOS");
    opcion[3].setCharacterSize(60);
    opcion[3].setPosition(70,500);
    opcion[3].setColor(sf::Color(100,0,50));

    opcion[4].setString("SALIR");
    opcion[4].setCharacterSize(60);
    opcion[4].setPosition(950,500);
    opcion[4].setColor(sf::Color(100,0,50));
    sel=0;
    return true;
}
void cScreen::dibujarSprite(){
    ventana.draw(fon1);
    for(int i=0;i<numero;i++){
        ventana.draw(opcion[i]);
    }
}

void cScreen::moveUp(){
    if(sel-1>=0){
        opcion[sel].setColor(sf::Color(100,0,50));
        sel--;
        opcion[sel].setColor(sf::Color(255,180,255));
        s.play();
    }
}
void cScreen::moveDown(){
    if(sel+1<numero){
        opcion[sel].setColor(sf::Color(100,0,50));
        sel++;
        opcion[sel].setColor(sf::Color(255,180,255));
        s.play();
    }

}
void cScreen::accion()
{
    /*if(!inicio)
    {
        std::cout<<"fallo al iniciar al juego "<<std::endl;
        return ;
    }*/
    while(ventana.isOpen())
    {
        sf::Event event;
        while(ventana.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Up:
                            moveUp();
                            break;
                        case sf::Keyboard::Down:
                            moveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch(GetPressedItem())
                                {
                                case 0:
                                std::cout<<"play apretaste el boton"<<std::endl;
                                ventana.close();
                                correr.iniciar();
                                    break;
                                case 1:
                                    std::cout<<"scores apretaste el boton "<<std::endl;
                                    break;
                                case 2:
                                    std::cout<<"minijuego apretaste el boton"<<std::endl;
                                    break;
                                case 3:
                                    std::cout<<"creditos apretaste el boton "<<std::endl;
                                    break;
                                case 4:
                                    ventana.close();
                                    break;
                    }
                    break;
                }
            break;
                                case sf::Event::Closed:
                                    ventana.close();
                                    break;
            }
        }
        ventana.clear();
        dibujarSprite();
        ventana.display();
    }
}

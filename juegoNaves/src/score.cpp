#include "score.h"
#include<sstream>
#include <cstring>
#include "SFML/Graphics.hpp"
using namespace sf;
score::score()
{
    puntoPlayer=0;
    pointIA=0;
    fuente1=new Font();
    fuente1->loadFromFile("ACafe.ttf");//cargamos fuente
    textPlayer=new Text();
    textPlayer->setFont(*fuente1);//cargando texto
    //textPlayer->setString("hola");
    textPlayer->setCharacterSize(50);
    textPlayer->setColor(sf::Color::Yellow);

}
void score::show(sf::RenderWindow &ventana){
    std::stringstream ia;
    ia<<puntoPlayer;
    std::string puntoplayer_string;
    puntoplayer_string="NIVEL 1: "+ia.str();
    textPlayer->setString(puntoplayer_string);

    //st.push_back('0'+puntoPlayer);
    //textPlayer->setString(st);
     //textPlayer->setCharacterSize(100);
    //textPlayer->setColor(sf::Color::Yellow);
    //textPlayer->setPosition(ancho+textPlayer->getLocalBounds().ancho,20);
    textPlayer->setPosition(200,10);
    ventana.draw(*textPlayer);

}


score::~score()
{
    //dtor
}

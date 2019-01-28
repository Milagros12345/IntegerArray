#include "enemies.h"
#include "nave.h"
#include<SFML/Graphics.hpp>
enemies::enemies(Vector2f tam){
    enemi.setSize(tam);
    enemi.setFillColor(Color::Blue);
}
void enemies::dibuja(RenderWindow &ventana){
    ventana.draw(enemi);
}
void enemies::setPosition1(int x_,int y_){
    enemi.setPosition(x_,y_);
}
void enemies::mover(Vector2f dis){
    enemi.move(dis);
}
enemies::~enemies()
{
    //dtor
}

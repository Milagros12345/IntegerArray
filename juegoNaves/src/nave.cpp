#include "nave.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
float nave::posx(){
    return nave1.getPosition().x;}
float nave::posy(){
    return nave1.getPosition().y;}
void nave::setPosition(int x_,int y_){
    nave1.setPosition(x_,y_);
}
nave::nave2(Vector2f size){
    nave1.setSize(size);
    nave1.setFillColor(Color::Red);
}
int nave::getSizey(){
    return nave1.getSize().y;
}
int nave::getSizex(){
    return nave1.getSize().x;}
void nave::move(Vector2f dis){
    nave1.move(dis);
}
void nave::dibujar(RenderWindow &ventana){
    ventana.draw(nave1);
}
nave::~nave()
{
    //dtor
}

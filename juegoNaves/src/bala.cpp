#include "bala.h"
#include "enemies.h"
#include<SFML/Graphics.hpp>
using namespace sf;
bala::bala(Vector2f tam)
{
    bala1.setSize(tam);
    bala1.setFillColor(Color::Yellow);

}
 void bala::fire(float speed)
{
    bala1.move(0, speed);
}
int bala::getRight()
{
    return bala1.getPosition().x + bala1.getSize().x;
}
int bala::getTop()//ARRIBA
{
    return bala1.getPosition().y;
}
int bala::getBottom()//abajo
{
    return bala1.getPosition().y + bala1.getSize().y;
}

void bala::draw(RenderWindow &window)
{
    window.draw(bala1);
}
void bala::setPos(Vector2f newPos)
{
   bala1.setPosition(newPos);
}
bool bala::colicion(enemies a){
    Vector2f p1(bala1.getPosition().x,getTop());
    Vector2f p2=p1+bala1.getSize();
    Vector2f p3(a.posx(),a.posy());
    Vector2f p4=p3+bala1.getSize();
    if(p2.x>p3.x && p1.x<p4.x &&p2.y>p3.y && p1.y<p4.y)
        return true;
    else return false;
}


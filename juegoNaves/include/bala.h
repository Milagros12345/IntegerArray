#ifndef BALA_H
#define BALA_H
#include "enemies.h"
#include<SFML/Graphics.hpp>
using namespace sf;
class bala
{
    RectangleShape bala1;


    public:

        bala(Vector2f tam);
        void fire(float speed);
        int getRight();

        int getLeft();

        int getTop();

        int getBottom();

        int posX(){return bala1.getPosition().x;};

        int posY(){return bala1.getPosition().y;};

        void draw(RenderWindow &window);

        void setPos(Vector2f newPos);
        bool colicion(enemies a);
};

#endif // BALA_H

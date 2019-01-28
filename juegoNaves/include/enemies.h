#ifndef ENEMIES_H
#define ENEMIES_H
#include "nave.h"
#include<SFML/Graphics.hpp>
class enemies:public nave
{
    public:
        enemies(Vector2f tam);
        enemies(){}
        void dibuja(RenderWindow &ventana);
        void setPosition1(int x_,int y_);
        void mover(Vector2f dis);
        virtual ~enemies();


        int x,y;
        RectangleShape enemi;
};

#endif // ENEMIES_H

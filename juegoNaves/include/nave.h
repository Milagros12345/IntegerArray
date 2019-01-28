#ifndef NAVE_H
#define NAVE_H
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class nave
{
    public:
        nave(){};
        nave2(Vector2f size);
        void dibujar(RenderWindow &a);
        ~nave();
        void move(Vector2f dis);
        int getSizey();
        int getSizex();
        float posx();
        void setPosition(int x_,int y_);
        float posy();
    private:
        int x,y;
        RectangleShape nave1;
        Texture textura;
};

#endif // NAVE_H

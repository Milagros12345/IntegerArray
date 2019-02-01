#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <string.h>
#include "polygon.h"
class Rectangle:public polygon
{
    public:
        int area(){return widht*height;}

};

#endif // RECTANGLE_H

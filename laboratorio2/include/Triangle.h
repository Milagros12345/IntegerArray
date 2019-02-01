#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>
#include "polygon.h"
class Triangle:public polygon
{
    public:
        int area();
        virtual ~Triangle();
};

#endif // TRIANGLE_H

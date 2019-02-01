#include "polygon.h"
#include <iostream>
using namespace std;
polygon::~polygon()
{
    //dtor
}
int polygon::area(){
    return widht*height;
}
void polygon::set_value(int a,int b){widht=a;height=b;}
void polygon::print(){cout<<this->area()<<endl;}

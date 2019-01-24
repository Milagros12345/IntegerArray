#include "point.h"
#include <iostream>
using namespace std;
point::point()
{
    x=0.0;
    y=0.0;
}
point::point(double x,double y){
    this->x=x;
    this->y=y;
}
point::point(const point &o)//debe ser constante porque estamos inicializando
{
    this->x=o.x;
    this->y=o.y;
}
void point::setvalue(double x,double y){
    this->x=x;
    this->y=y;
}
double point::getx(){return x;}
double point::gety(){return y;}
void point::print(){
    cout<<"("<<x<<","<<y<<")"<<endl;
}
point::~point()
{
    //dtor
}

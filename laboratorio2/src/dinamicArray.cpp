#include "dinamicArray.h"
#include "polygon.h"
dinamicArray::dinamicArray()
{
    size=0;
    arr= new polygon*[size];
}
dinamicArray::dinamicArray(polygon *p[],int size){
    this->size=size;
    arr=new polygon *[size];
    for(int i=0;i<size;i++)
        arr[i]=p[i];
}
dinamicArray::dinamicArray(dinamicArray &o){
    size=o.size;
    arr=new polygon *[o.size];
    for(int i=0;i<size;i++)
        arr[i]=o.arr[i];
}
void dinamicArray::insertar(polygon *val,int pos){
    if(pos>=0 && pos-size)
        for(int i=size-1;i>pos;i--)
            arr[i]=arr[i-1];
        arr[pos]=val;

}
void dinamicArray::eliminar(int pos){
    for(int i=pos;i<size;i++)
        arr[i]= arr[i+1];
    resize(size-1);
}
dinamicArray::~dinamicArray()
{
    delete [] arr;
}
void dinamicArray::push_back(polygon *val){
    resize(size+1);
    arr[size-1]=val;
}
void dinamicArray::print(){
    for(int i=0;i<size;i++)
       std::cout<<arr[i]<<" "<<std::endl;
}




#ifndef DINAMICARRAY_H
#define DINAMICARRAY_H
#include "polygon.h"
#include <iostream>
class dinamicArray
{
    public:
        dinamicArray();
        dinamicArray(polygon *p[],int size);
        dinamicArray(dinamicArray &o);
        void insertar(polygon *val,int pos);
        void eliminar(int pos);
        ~dinamicArray();
        void push_back(polygon *val);
        void print();
    protected:
        void resize(int newsize){
            polygon **p=new polygon *[newsize];
            int m=newsize>size?size:newsize;
            for(int i=0;i<m;i++)
                p[i]=arr[i];
            delete[]arr;
            size=newsize;
            arr=p;
        }
    private:
        polygon**arr;
        int size;
};

#endif // DINAMICARRAY_H

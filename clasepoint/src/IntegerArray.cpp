#include "IntegerArray.h"
#include<iostream>
using namespace std;
IntegerArray::IntegerArray() {
        data = new int[0];
        this->size = 0;
    }
IntegerArray::IntegerArray(int arr[], int size) {
        this->data = new int[size];
        this->size = size;
        for (int i = 0; i < size; ++i)
            data[i] = arr[i];
    }
IntegerArray::IntegerArray(IntegerArray &o) {
        data = new int[o.size];
        size = o.size;
        for (int i = 0; i < size; ++i)
            data[i] = o.data[i];
    }
void IntegerArray::resize(int newsize){
    int *pts=new int[newsize];
    int minn=(newsize>size)?size:newsize;
    for(int i=0;i<minn;i++)
        pts[i]=data[i];
    delete [] data;
    size=newsize;
    data=pts;
}
void IntegerArray::push_back(const int val) {
    resize(size+1);
    data[size-1]=val;
    }
void IntegerArray::insert(const int val, const int pos) {
    resize(size+1);
    for(int i=size-1;i>pos;i--)
        data[i]=data[i-1];
    data[pos]=val;
    }

void IntegerArray::remove(const int pos) {
    if(pos>=0 && pos<size)
        for(int i=pos;i<size-1;i++){
            data[i]=data[i+1];
        }
    resize(size-1);

    }
void IntegerArray::print() {
        for(int i =0; i < size; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
int IntegerArray::getSize() {
        return size;
    }
IntegerArray::~IntegerArray() {
        delete[] data;
    }

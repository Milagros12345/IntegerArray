#include <iostream>
#include "point.h"
#include "IntegerArray.h"
void swap1(point &a,point &b){
    point c=a;
    a=b;
    b=c;
}
void swap2(point *a,point *b){
    point c=*a;
    *a=*b;
    *b=c;
}
using namespace std;
void orden(point a[],int t){
    for(int i=0;i<t-1;i++){
        for(int j=0;j<t-i-1;j++)
            if(a[j].getx()>a[j+1].getx())
                swap1(a[j],a[j+1]);
        }
}
void ordeP(point *a,int t){
    for(int i=0;i<t;i++){
        for(int j=0;j<t-1;j++){
            if((a+j)->getx(),(a+j+1)->getx())//0 *(a+j).getx()
                swap2(a+j,(a+j+1));//0 &a[j],&a[j+1]
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    //point p;
    point p1[]={point(2,3),point(8,7),point(3,7),point(5,8)};
    int t=sizeof(p1)/sizeof(p1[0]);
    orden(p1,t);
    p1[0].print();
    (*p1).print();
    p1->print();//puntero usar flecha
    (p1+1)->print();
//llamado con punteros
    cout<<"con punteros "<<endl;
    ordeP(p1,t);
    for(int i=0;i<t;i++){
        (p1+i)->print();
    }
    //transformamos los array a hieht con new y delete
    point *arr=new point[t];
    for(int x=0;x<t;x++){
        arr[x]=p1[x];
    }
    cout<<"en heigt "<<endl;
    for(int i=0;i<t;i++){
        (arr+i)->print();
    }
    delete[] arr;
    //lo que hizo el profesor
    point *a=new point[5];//tienes poner el tamaño es obligatorio
    a[0].setvalue(4,4);


    int arr1[] = {1,2,3,4,5};
    IntegerArray a1(arr1, 5);
    a1.print();
    a1.push_back(6);
    a1.print();
    a1.insert(10,5);
    a1.print();
    a1.remove(5);
    a1.print();
    //cout << a.getSize() << endl; // 4
    return 0;
}

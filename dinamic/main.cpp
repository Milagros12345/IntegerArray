#include <iostream>

using namespace std;

template <typename T>
class Point {
    T x, y;
public:
    Point(const T a = 0, const T b = 0) : x(a), y(b) {}
    T getX();
    T gety();
};

template <typename T>
T Point<T>::getX() {
    return x;
}
template <typename T>
T Point<T>::gety(){
    return y;
}


template <typename T>
class DynamicArray {
    T *data;
    int size;
public:
    DynamicArray() {
        data = new T[0];
        this->size = 0;
    }

    DynamicArray(T arr[], int size) {
        this->data = new T[size];
        this->size = size;
        for (int i = 0; i < size; ++i)
            data[i] = arr[i];
    }

    DynamicArray(DynamicArray &o) {
        data = new T[o.size];
        size = o.size;
        for (int i = 0; i < size; ++i)
            data[i] = o.data[i];
    }

    void push_back(T val) {
        this ->size = size+1;
        T *arr = new T[size];

        for(int i=0;i<size-1;++i){
            arr[i]=data[i];
        }
        arr[size-1]=val;
        delete[] data;
        data = arr;
    }

    void insert(T val, int pos) {
        this->size= size +1;
        T *arr1 = new T[size];
        for( int i = 0, j = 0; i < size ; i++, j++){
            if ( i == pos ){
                arr1[i] = val;
                j--;
            }
            else
                arr1[i]= data[j];
        }
        delete[] data;
        data = arr1;
    }

    void remove(int pos) {
        this->size--;
        T *arr = new T[size];

        for (int i=0, j=0; i<size; ++i, ++j)
        {
            if (i==pos) j++;
            arr[i] = data[j];
        }

        delete[] data;
        data = arr;
    }
    //friend ostream& operator <<(ostream &a,ostream &b){
    //}
    int getSize() {
        return size;
    }

    ~DynamicArray() {
        delete[] data;
    }
};
template <typename T>
ostream& operator<<(ostream &output,Point<T> &a){
    output<<" ("<<a.getX()<<","<<a.gety()<<")";
    return output;
}
int main() {
    int arr[] = {1,2,3,4,5};
    DynamicArray<int> a(arr, 5);
    a.push_back(6);
    a.insert(10,5);
    //a.print();
    a.remove(5);

    Point<int> arrPoints[2] = {Point<int>(2,3), Point<int>(4,5)};

    DynamicArray<Point<int> > daPoints(arrPoints, 2);
    Point<int> p(2,9);
    for(int i=0;i<2;i++)
        cout<<*(arrPoints+i);
    daPoints.push_back(p);
    return 0;
}

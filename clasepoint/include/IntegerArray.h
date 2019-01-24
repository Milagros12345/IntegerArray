#ifndef INTEGERARRAY_H
#define INTEGERARRAY_H
class IntegerArray
{
    public:
    int *data;
    int size;
    IntegerArray();
    IntegerArray(int arr[], int size);
    IntegerArray(IntegerArray &o);
    void resize(int newsize);
    void push_back(int val);
    void insert(int val, int pos);
    void remove(int pos);
    void print();
    int getSize();
    ~IntegerArray();
};

#endif // INTEGERARRAY_H

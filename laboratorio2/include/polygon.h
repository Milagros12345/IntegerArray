#ifndef POLYGON_H
#define POLYGON_H
class polygon
{
    public:
        void set_value(int x,int y);
        virtual int area()=0;
        void print();
        int getw(){return widht;}
        int geth(){return height;}
        virtual ~polygon();

    protected:
        int widht,height;
};

#endif // POLYGON_H

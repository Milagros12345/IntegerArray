#ifndef POINT_H
#define POINT_H


class point
{
    public:
        point();
        point(double,double);
        point(const point &o);
        double getx();
        double gety();
        void print();
        void setvalue(double x,double y);
        virtual ~point();

    protected:

    private:
        double x,y;


};

#endif // POINT_H

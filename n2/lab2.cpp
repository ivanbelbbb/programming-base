#include <iostream>
using namespace std;

class Circle
{
public:
    Circle(float x=0.0f, float y=0.0f, float radius=1.0f);
    Circle(const Circle &circle_for_copy);
    void define_dot(float x, float y);
    void print();
    ~Circle();
private:
    float xo;
    float yo;
    float r;
};


int main()
{
    Circle circle1;
    circle1.print();
    circle1.define_dot(0.25, 0.5);


    Circle circle2{1,2,2};
    circle2.print();
    circle2.define_dot(5,5);

    Circle circle3(circle1);
    circle3.print();
    circle3.define_dot(-5,-5);

    return 0;
}

void Circle::define_dot(float x, float y)
{
    if ((x-xo)*(x-xo) + (y-yo)*(y-yo) <= r*r){
        cout << "(" <<x << ", " << y << ")" << " in circle" << endl;
    } else {
        cout<< "(" <<x << ", " << y << ")" << " not in cirle" << endl;
    }
}

void Circle::print(){
    cout << "Cirlce params: \n" << "Xo = " << xo << "\nYo = " << yo << "\n radius = " << r << endl;
}

Circle::Circle(float x, float y, float radius)
{
    xo = x;
    yo = y;
    if (radius > 0){
        r = radius;
    } else {
        cout << "ERROR: radius must be positive"<< endl;
    }
}

Circle::Circle(const Circle &circle_for_copy)
{
    xo = circle_for_copy.xo;
    yo = circle_for_copy.yo;
    r = circle_for_copy.r;
}

Circle::~Circle()
{
    cout << "Объект Circle уничтожен." << endl;
}
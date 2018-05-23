#include <iostream>

///Difference between inheritance of interface and inheritance of implementation
///function interface vs. function implementation

class Shape
{
public:
    Shape(){}
    virtual ~Shape(){}
    
    virtual void draw() const = 0;
    virtual void error(const std::string & msg)
    {
        std::cout<<"default error"<<std::endl;
    }
    int objectID() const
    {
        return 0;
    }
    //...
};


class Rectangle: public Shape
{
public:
    void draw() const
    {
        std::cout<<"Rectangle::draw"<<std::endl;
    }
    void error(const std::string &msg)
    {
        std::cout<<"Rectangle::error"<<std::endl;        
    }
};

class Ellipse: public Shape
{
public:
    void draw() const
    {
        std::cout<<"Ellipse::draw"<<std::endl;
    }
};

int main()
{
//    Shape * ps = new Shape; //!error, Shape is an abstract class
    Shape *ps1 = new Rectangle;
    ps1->draw(); //Rectangle::draw
    std::string msg = "233";
    ps1->error(msg);
    Shape *ps2 = new Ellipse;
    ps2->draw(); //Ellipse::draw
    ps2->error(msg);
//    ps1->Shape::draw(); //!error
//    ps2->Shape::draw();

    delete ps1;
    delete ps2;

    return 0;
}

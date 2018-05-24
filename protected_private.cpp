#include <iostream>

///private members are inaccessible to derived classes, 
///however, protected members are accessible to derived classes

class Base
{
public:
    explicit Base(int val1, int val2):id(val1),
    num(val2)
    {
    
    }
    virtual ~Base()
    {

    }
    int addNum(const Base & foo) const
    {   
        return this->num + foo.num; //!OK
    }

    int addId(const Base & foo) const
    {
        return this->id + foo.id; //!OK,like private for base class
    }
protected:
    int id;
private:
    int num;
};


class Derived:public Base 
{
public:
    using Base::Base; //inhiriting constructor, -std=c++11
    int getNum() const 
    {
//        return num; //!error, Base::num is private
        return 0;
    }
    int getId() const
    {
        return id;
    }
    int getId(const Derived & foo) 
    {
        return foo.id; //!OK
    }
    int getId(const Base & foo) 
    {
//        return foo.id; //!error, inaccessible
        return -1;
    }

};

class Derived2: protected Base //public, protected,private ==> protected, protected, private
{
public:
    using Base::Base;
    int getId() const
    {
        return id; //!OK, Base::id is protected
    }

};


int main()
{
//    Base t; //!error: no matching function for call to ‘Base::Base()’

    Base t1(1,100);
    Base t2(2,233);

    std::cout<<"addNum:"<< t1.addNum(t2) << std::endl;
    std::cout<<"addId:" << t1.addId(t2) << std::endl;

    Derived t3(5,520);
    Derived t4(6,33);
//    std::cout<<"getNum:"<< t3.getNum() << std::endl;
    std::cout<<"getId of t3:" << t3.getId() << std::endl;
    std::cout<<"getId of t1:" << t3.getId(t4) << std::endl; 

    Derived2 d1(20, 520);
    Derived2 d2(21, 111);
    std::cout<<"Derived2 getId of d1:"<< d1.getId() << std::endl;
//    d1.addNum(d2); //!error, Base::addNum is protected now in the scope of Derived
    

    return 0;
}

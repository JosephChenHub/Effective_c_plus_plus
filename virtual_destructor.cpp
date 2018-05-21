#include <iostream>

///if you use virtual functions in base class, then you should declare
///destructors virtual in polymorphic base classes

class base1
{
public:
    base1()
    {

    }
    ~base1() //!non-virtual
    {
        std::cout<<"non-virtual destructor of class base1!"<<std::endl;
    }
    virtual void doSomething() {};
};

class base2
{
public:
    base2()
    {

    }
    virtual ~base2() //!virtual
    {
        std::cout<<"virtual destructor of class base2!"<<std::endl;
    }

    virtual void doSomething() {};

};

class myDerived1: public base1
{
public:
    myDerived1()
    {

    }
    ~myDerived1()
    {
        std::cout<<"destructor of class myDerived1!"<<std::endl;
    }

    void doSomething()
    {
        std::cout<<"doSomething called by myDerived1!"<<std::endl;
    }

};

class myDerived2: public base2
{
public:
    myDerived2()
    {

    }
    ~myDerived2()
    {
        std::cout<<"destructor of class myDerived2!"<<std::endl;
    }

    void doSomething()
    {
        std::cout<<"doSomething called by myDerived2!"<<std::endl;
    }

};





int main(int argc, char * argv[])
{
    std::cout<<"test base1..."<<std::endl;
    base1 *t1 = new myDerived1(); 
    delete t1;

    std::cout<<"test base2..."<<std::endl;
    base2 *t2 = new myDerived2();
    delete t2;


    return 0;
    
}

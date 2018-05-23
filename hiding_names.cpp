#include <iostream>

/*========== Avoid hiding inherited names ================================
Shakespeare had a thing about names. "What's in a name?" he asked, 
"A rose by any other name would smell as sweet." 
The Bard also wrote,
"he that filches from me my good name ... makes me poor indeed."
========================================================================*/

class Base
{
public:
    Base() {} 
    virtual ~Base() 
    {
        std::cout << "Base destructor"<<std::endl;
    }

    virtual void mf1() = 0;
    virtual void mf2()
    {
        std::cout << "Base::mf2" << std::endl;
    }
    void mf3()
    {
        std::cout<< "Base::mf3"<<std::endl;
    }
};


class Derived: public Base
{
public:
    Derived(){}
    ~Derived()
    {
        std::cout<<"Derived destructor"<<std::endl;
    }
    virtual void mf1()
    {
        std::cout<< "Derived::mf1" << std::endl;
    }
    void mf3()
    {
        std::cout<< "Derived::mf3" << std::endl;
    }
    void mf4()
    {
        std::cout<<"Derived::mf4"<< std::endl;
        Base::mf3();
    }

};


int main()
{
    Derived *t = new Derived;
    t->mf1(); //Derived
    t->mf2(); //Base
    t->mf3(); //Derived, hiding
    t->mf4(); //Derived::mf4, Base:mf3

    delete t; //Derived , Base destructor

    return 0;
}    

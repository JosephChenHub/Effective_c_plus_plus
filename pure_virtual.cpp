#include <iostream>


using namespace std;


class Base //abstract class
{
public:
    Base()
    {
    }
    virtual ~Base()
    {
        cout<<"base destructor..."<<endl;
    }

    virtual void size() = 0;
};

void Base::size()
{
    cout<<"size called by base"<<endl;
}

class Derive:public Base
{

public:
    Derive() {}
    ~Derive()
    {
        cout<<"derive destructor..."<<endl;
    }
    void size()
    {   
        cout<<"size called by derive"<<endl;
        cout<<"Now we call Base::size"<<endl;
        Base::size();
    }

};




int main(int argc, char * argv[])
{

    Base *ptr = new Derive;
    ptr->size();
    delete ptr;
    
    ///ptr = new Base; //!error: invalid new-expression of abstract class type ‘Base’
    ///delete ptr;
    
    return 0;
}

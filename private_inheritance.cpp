#include <iostream>


using namespace std;

///here is public inheritance example
class Person
{
public:
    Person()
    {
        cout<<"Person instance constructed..."<<endl;
        num = 0;
    }
    ~Person()
    {

    }
    int getNum()const
    {
        return num;
    }
    void setNum(int val)
    {
        num = val;
    }
private:
    int num;
};

class Student1:public Person
{
public:
    Student1()
    {
        setNum(10);
        cout<<"Student1 instance constructed. getNum"<<getNum()<<endl;
    }
};

class Student2:private Person  //private inheritance is is-implemented-in-terms-of rather than is-a
{
public:
    Student2()
    {
        setNum(10);
        cout<<"Student2 instance constructed. getNum"<<getNum()<<endl;
    }
};

void eat(const Person &p)
{
    cout<<"getNum of this Person:"<< p.getNum() << endl;
}

///comparison of object's size
class Empty{};

class HoldsAnInt1
{
private:
    int x;
    Empty e;
};

class HoldsAnInt2:private Empty
{
private:
    int x;
};

int main(int argc, char * argv[])
{
    cout<<"this is the base class Person:"<<endl;
    Person p;
    cout<<"this is the derived class Student1:"<<endl;
    Student1 s1;
    cout<<"this is the derived class Student2:"<<endl;
    Student2 s2;
    
    eat(p);
    eat(s1);
///    eat(s2); //! error: ‘Person’ is an inaccessible base of ‘Student2’
    
    cout<<"sizeof(HoldsAnInt1):"<<sizeof(HoldsAnInt1)<<endl; //! if 64-bit, =8
    cout<<"sizeof(HoldsAnInt2):"<<sizeof(HoldsAnInt2)<<endl; //  = 4 
    
    return 0;
}  

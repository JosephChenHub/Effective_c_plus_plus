#include <iostream>

using namespace std;

class Test
{
public:
    Test()
    {
        num1 = 0;
        num2 = 0;
    }
    ~Test()
    {

    }
    int getNum1() const //const *this
    {
        int x =233;
        //num1 = 100; //!error
        return num1+x;
    }
    int getNum2() const
    {
        int x = 233;
        num2 = 100; //this->num is mutable
        return num2+x;
    }

private:
    int num1;
    mutable int num2;
};


int main()
{
    char greeting[] = "Hello";
    char world[] = "world";
    const char *p1 = greeting;       // const data, non-const pointer
    char * const p2 = greeting;      // const pointer, non-const data
    const char * const p3 = greeting; //const pointer, const data
   
    p1 = world; //OK
//    p2 = world; //!error: assignment of read-only variable
//    p3 = world; //!error
    Test t;
    cout<<"t.getNum1():" << t.getNum1() 
        <<"\t t.getNum2():"<< t.getNum2()<<endl;


    return 0;
}    

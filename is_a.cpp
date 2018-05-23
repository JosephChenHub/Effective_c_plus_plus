#include <iostream>

///public inheritance ==> is-a

class Person
{


};

class Student:public Person
{


};


void eat(const Person & p)
{

}

void study(const Student &s)
{

}


int main()
{
    Person p;
    Student s;

    eat(p); //!OK
    eat(s); //!OK

//    study(p); //!error
    study(s);

    return 0;
}    
    

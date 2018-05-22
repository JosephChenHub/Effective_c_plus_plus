#include <iostream>


class Empty
{

};

class HomeForSale
{
public:
    HomeForSale()
    {

    }
    ~HomeForSale()
    {

    }

private:
    HomeForSale(const HomeForSale &);
    HomeForSale & operator=(const HomeForSale &);
};



int main()
{
    Empty e1;  //default constructor
    Empty e2(e1);  //copy
    Empty e3 = e1; //copy assignment
    
    HomeForSale h1; 
//    HomeForSale h2(h1); //!error, private
//    HomeForSale h3 = h1; //!error

    return 0;

}    

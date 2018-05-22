#include <iostream>
#include <vector>
#include <stdexcept>
#include <string.h>
///you should prevent exceptions from leaving destructors

class Widget
{
public:
    Widget():
    id(0), size(0), data(NULL)
    {
    
    }
    Widget(int val)
    {
        id = val;
        size = id+1;
        data = new int [size];
    }
    Widget(const Widget &rhs) //deep copy 
    {
        id = rhs.id;
        size = rhs.size;
        data = new int[size];
        memcpy(data, rhs.data, sizeof(int)*size);
    }
    friend void swap(Widget & lhs, Widget &rhs)
    {
        using std::swap;
        std::cout<<"swap, id:" << lhs.id<<std::endl;
        swap(lhs.id, rhs.id);
        swap(lhs.size, rhs.size);
        swap(lhs.data, rhs.data);
        std::cout<<"swap, id:" << lhs.id<<std::endl;

    }
    /*
    Widget & operator = (Widget rhs) //pass by value, however, ``data'' will free twice
    {
        swap(*this, rhs);
        return *this;
    }
    */
    Widget& operator= (const Widget &rhs) //deep copy, ``data'' has different address
    {
        std::cout << "copy assignment"<< std::endl;
        Widget tmp(rhs);
        swap(*this, tmp);
        
        return *this;
    }
    
    ~Widget()
    {
        std::cout<<"id:"<< id << " destructor called..." << std::endl;
        if(data != NULL)
        {
            delete [] data;
            data = NULL;
        }
    }
    int getId() const
    {
        return id;
    }
    int getSize() const
    {
        return size;
    }
    //....
private:
    int *data;
    int id;
    int size;
};


void doSomething()
{
    
    std::vector<Widget>v;
    for(int i = 0; i < 5; ++i)
    {
        Widget item(i);
        v.push_back(item);
    }
    std::cout<<"Test case2:"<<std::endl;
    Widget t1(15);
    Widget t2;
    Widget t3;
    t2 = t1;

}

int main()
{
    doSomething();

    return 0;
}    

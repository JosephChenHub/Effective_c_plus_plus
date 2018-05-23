#include <iostream>
#include <vector>

///Understand the two meanings of typename

///There is no difference between max1 and max2
template<class T>
T max1(const T & a, const T &b) 
{
    return a > b? a : b;
}

template<typename T>
T max2(const T &a, const T &b)
{
    return a > b? a : b;
}

///you must use typename in some case
template<typename C>
void print2nd(const C & container)
{
    if(container.size() >= 2)
    {
//        C::const_iterator iter(container.begin()); //! error: ‘iter’ was not declared in this scope
        typename C::const_iterator iter(container.begin()); //! OK
        ++iter;
        std::cout << *iter << std::endl;
    }
}



int main()
{
    float a = 3.5, b = 2.4;
    std::cout<<" max(a,b):"<< max1(a, b) << std::endl;
    std::cout<<" max(a,b):"<< max2(a, b) << std::endl;
    
    int c = 2, d = 4;
    std::cout<<" max(a,b):"<< max1(c, d) << std::endl;
    std::cout<<" max(a,b):"<< max2(c, d) << std::endl;
    
    std::vector<int> data;
    data.push_back(101);
    data.push_back(120);
    print2nd(data);
    
    return 0;
}    

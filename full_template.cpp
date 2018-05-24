#include <iostream>

namespace myAI{

template<typename T>
void swap(T &A, T &B)
{
    std::cout<<"swap--Partially specialize"<<std::endl;
    T tmp = A;
    A = B;
    B = tmp;

}

template <>
void swap<double>(double &A, double &B)
{
    std::cout<<"swap--Total template specialization for ``double''"<<std::endl;
    double tmp = A;
    A = B;
    B = tmp;
}

}

int main(int argc, char * argv[])
{
    double a = 3, b = 2.5;
    float c = 2.5, d = 1.9;

    myAI::swap(c,d);
    myAI::swap(a,b);

    
    return 0;
}    

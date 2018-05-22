#include <iostream>

using namespace std;


int main()
{
    int size = 5;
    int * t1 = new int[size];
    int * t2 = NULL;
    for(int i = 0; i < size; ++i)
    {
        t1[i] = i;
    }
    std::swap(t1, t2);
    for(int i = 0; i < size; ++i)
    {
        std::cout << t2[i] << " ";
    }
    std::cout << std::endl;
    

    delete [] t1;
    delete [] t2;

    return 0;
}    

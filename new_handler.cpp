#include <iostream>

using namespace std;

void outOfMem()
{
    std::cerr << "Unable to allocate such memory! "<< std::endl;
    std::abort();
}


int main()
{
    std::set_new_handler(outOfMem);
    int *pBigDataArray = new int[1000000000000L];
    delete [] pBigDataArray;

    return 0;
}    

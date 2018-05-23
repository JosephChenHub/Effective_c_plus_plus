///prefer pass-by-reference-to-const to past-by-value

#include <iostream>
#include <time.h>
#include <string.h>

class Test
{
public:
    Test()
    {
        size = 100000;
        test_size = 10;
        data = new int[size]; //create a big array
        for(size_t i = 0; i < test_size; ++i)
        {
            data[i] = i;
        }
    }
    ~Test()
    {
        if(data != NULL)
        {
            delete [] data;
            data = NULL;
        }
    }
    Test (const Test &rhs) //copy assignment, deep copy
    {
        size = rhs.size;
        test_size = rhs.test_size;
        if(data != NULL)
        {
            delete [] data;
        }
        data = new int[size];
        memcpy(data, rhs.data, sizeof(int)*size);
    }
    void info() const
    {
        std::cout << " Test.info() ..." <<std::endl;
        for(size_t i = 0; i < test_size; ++i)
        {
            std::cout << data[i] << " ";
        }
        std::cout<<std::endl;
    }
private:
    int * data;
    size_t size;
    size_t test_size;
};


void foo1(Test t) //pass-by-value
{
   t.info();
}

void foo2(const Test &t) //pass-by-reference
{
    t.info(); //const reference, you cannot call any member function that is not const or not static
}

int main()
{
    Test t;
    clock_t start, end;

    start = clock();
    foo1(t);
    end = clock();
    std::cout<< " foo1 cost"<< (end - start) << " ms" << std::endl;

    start = clock();
    foo2(t);
    end = clock();
    std::cout<< " foo2 cost"<< (end - start) << " ms" << std::endl;
    

    return 0;
}    

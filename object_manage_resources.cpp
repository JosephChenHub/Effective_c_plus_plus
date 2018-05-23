#include <iostream>

#include <tr1/memory> //

using namespace std;

///heap-base memory manage
///

class Investment
{
public:
    Investment()
    {
        std::cout << " Investment constructor..." << std::endl;
    }
    ~Investment()
    {
        std::cout << " Investment destructor..." << std::endl;
    }
    void test()
    {
        std::cout<< " just a test" << std::endl;
    }
};


void foo1()
{
    Investment * pInv = new Investment;
    //...
    delete pInv; //!you may forget to free resources

}

void foo2()
{
    std::auto_ptr<Investment> pInv1(new Investment);
    std::auto_ptr<Investment> pInv2(pInv1); //now pInv1=NULL
    pInv1 = pInv2; //now pInv2 = NULL
    pInv1->test();
    pInv2->test();//indeed, pInv2 is null now

    ///share_ptr is reference-counting smart pointer
    std::tr1::shared_ptr<Investment> pInv3(new Investment); 
    std::tr1::shared_ptr<Investment> pInv4(pInv3); //neither null
    pInv3 = pInv4; //same

}

int main()
{
    foo1();
    foo2();
    
    return 0;
}

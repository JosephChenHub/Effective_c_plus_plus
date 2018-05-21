#include <iostream>

#include<vector>

using namespace std;

class myType
{
public:
    myType()
    {


    }
    ~myType()
    {
        if(data.size())
        {
           data.clear();
        }
    }
    void setData(int * src, int size)
    {
        if(data.size())
        {
           data.clear();
        }
        for(int i = 0; i < size; ++i)
        {
            data.push_back(src[i]);
        }
    }
    void printData()
    {
        if(!data.size())
        {
            return;
        }
        for(int i = 0; i < data.size(); ++i)
        {
            cout<<" " << data[i];
        }
        cout<<endl;
    }
    int  operator [] (size_t pos)
    {
        if(pos > size())
        {
            return -1;
        }
        return data[pos];
    }

    myType & operator+(myType & rhs)
    {
        for(int i = 0; i < rhs.size(); ++i)
        {
            data.push_back(rhs[i]);
        }
        return *this;
    }

    size_t size() const
    {
        return data.size();
    }
private:
    vector<int>  data;
};




int main(int argc, char * argv[])
{
    myType t1, t2;
    int a[] = { 1, 3, 5};
    int b[] = {2,4};
    t1.setData(a, 3);
    t2.setData(b, 2);
    cout<<"t1:"<<endl;
    t1.printData();
    cout<<"t2:"<<endl;
    t2.printData();

    t1 = t1 + t2;
    cout<<"t1 + t2:"<<endl;
    t1.printData();

    return 0;
}    

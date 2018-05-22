#include <iostream>

using namespace std;

class CameraType1
{
public:
    CameraType1()
    {
        cout<<"CameraType1 is constructed..."<<endl;
        num = 0;
    }
    void setNum(int val)
    {
        num = val;
    }
    int getNum( ) const
    {
        return num;
    }
private:
    int num;
};

///local static, singleton 
class Camera
{
public:
    static CameraType1 &getInstance() //thread-safe in multiple threads after C+11
    {
        static CameraType1 cam;
        return  cam;
    }
private:
    Camera();
    ~Camera();
};


int main()
{
//    Camera cam; //!error: ‘Camera::Camera()’ is private
    Camera::getInstance().setNum(110);
    cout<<"getNum:"<< Camera::getInstance().getNum() << endl;
    Camera::getInstance().setNum(150);
    cout<<"getNum:"<< Camera::getInstance().getNum() << endl;
    
    return 0;
}    

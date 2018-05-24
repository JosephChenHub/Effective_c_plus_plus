#include <iostream>


class CompanyA
{
public:
    void sendCleartext(const std::string &msg)
    {

    }

};

class CompanyB
{
public:
    void sendCleartext(const std::string &msg)
    {

    }
};

class CompanyZ
{
public:
    void sendEncrypted(const std::string& msg)
    {

    }
};

class MsgInfo
{
    //....
};

template<typename Company>
class MsgSender
{
public:
    void sendClear(const MsgInfo & info)
    {
        std::string msg;
        Company c;
        c.sendCleartext(msg);
    }

};

///this is a total template specialization
template<>
class MsgSender<CompanyZ> //CompanyZ has no member ``sendCleartext''
{
public:
    void sendSecret(const MsgInfo& info)
    {
        
    }
};

template<typename Company>
class LoggingMsgSender: public MsgSender<Company>
{
public:
//    using MsgSender<Company>::sendClear; //method2--if uncommented,then line 49 is OK
    void sendClearMsg(const MsgInfo& info)
    {
        //sendClear(info); //!error
        this->sendClear(info); //!method1--OK
///        MsgSender<Company>::sendClear(info); //method3--OK
    }
};



int main()
{
    LoggingMsgSender<CompanyA> senderA;
    MsgInfo info;
    senderA.sendClearMsg(info);

    LoggingMsgSender<CompanyZ> senderZ;
//    senderZ.sendClear(info); //!error
    senderZ.sendSecret(info);
//    senderZ.sendClearMsg(info); //!error

    return 0;
}    

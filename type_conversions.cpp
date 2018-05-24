#include <iostream>

//#define USE_ERROR_CODE //if uncommented, you will see some errors

#ifdef USE_NON_TEMPLATES
class Rational
{
public:
    Rational(int numerator = 0, int denominator = 1)
    {
        num = numerator;
        den = denominator;
    }
    int numerator( ) const
    {
        return num;
    }
    int denominator()const
    {
        return den;
    }
#ifdef USE_ERROR_CODE
    const Rational operator *(const Rational & rhs) const
    {
        return Rational(this->num * rhs.num, this->den * rhs.den);
    }
#endif 
///    friend const Rational operator *(const Rational& lhs, const Rational& rhs); //no need, if uncommented, also OK
    
    void print()
    {
        std::cout<<num <<"/"<<den << std::endl;
    }
private:
    int num;
    int den;
};

///member vs. non-member, no need to be friend
#ifndef USE_ERROR_CODE
const Rational operator *(const Rational & lhs, const Rational& rhs)
{
    return Rational(lhs.numerator() * rhs.numerator(), 
                    lhs.denominator() * rhs.denominator());
}
#endif

#else
///template

template<typename DType>
class Rational
{
public:
    Rational(DType numerator = 0, DType denominator = 1)
    {
        num = numerator;
        den = denominator;
    }
    DType numerator() const
    {
        return num;
    }
    DType denominator() const
    {
        return den;
    }
    void print()
    {
        std::cout<< num <<"/" << den <<std::endl;
    }
#ifdef USE_ERROR_CODE  
    friend const Rational<DType> operator *(const Rational<DType> & lhs,
                    const Rational<DType> & rhs); //!error, friend declaration declares a non-template function 
#else                    
    friend const Rational<DType> operator *(const Rational<DType> & lhs,
                    const Rational<DType> & rhs)
    {
        return Rational<DType>(lhs.numerator() * rhs.numerator(), 
                        lhs.denominator() * rhs.denominator());
    }
#endif    
private:
    DType num;
    DType den;
};

#ifdef USE_ERROR_CODE
template<DType>
const Rational<DType> operator *(const Rational<DType> & lhs,
                    const Rational<DType> & rhs)
{
        return Rational<DType>(lhs.numerator() * rhs.numerator(), 
                        lhs.denominator() * rhs.denominator());
}
#endif

#endif


int main()
{
#ifdef USE_NON_TEMPLATES
    Rational oneHalf(1,2);
    Rational oneEighth(1, 8);
    Rational result = oneHalf * oneEighth; //!OK
    result = oneHalf * 2; //OK, implicit type conversion
    
    std::cout<<" oneHalf * 2:";
    result.print();
#ifndef USE_NON_MEMBER
    result = 2 * oneHalf; //! error
#else
    result = 2 * oneHalf; //!OK
#endif
#else
    Rational<int> oneHalf(1,2);
    Rational<int> oneEighth(1,8);
    
    Rational<int> result = oneHalf * oneEighth;

    result = 2 * oneHalf;
    std::cout<<" oneHalf * 2:";
    result.print();

#endif


    return 0;
}    

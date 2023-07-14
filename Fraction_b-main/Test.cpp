#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Division by 0")
{
    Fraction a(5,3), b(14,0);
    CHECK_THROWS(a/b);

    CHECK_THROWS(a / 0);
}
    


TEST_CASE("operator +")
{
Fraction a(5,3), b(14,20);
    CHECK((a+b).getNumerator() == 71);
    CHECK((a+b).getDenominator() == 30);

    CHECK((a+2.42).getNumerator() == 613);
    CHECK((a+2.42).getDenominator() == 150);
}

TEST_CASE("operator -"){
Fraction a(5,3), b(14,20);
    CHECK((a-b).getNumerator() == 29);
    CHECK((a-b).getDenominator() == 30);
CHECK((a-0.42).getNumerator() == 187);
    CHECK((a-0.42).getDenominator() == 150);
}

TEST_CASE("operator *"){
    Fraction a(5,3), b(14,20);
    CHECK((a*b).getNumerator() == 7);
    CHECK((a*b).getDenominator() == 6);
        Fraction  c(-14,20);
 CHECK((a*c).getNumerator() == -7);
    CHECK((a*c).getDenominator() == 6);
    CHECK((2.3*b).getNumerator() == 161);
    CHECK((2.3*b).getDenominator() == 100);
}

TEST_CASE("operator /"){
    Fraction a(5,3), b(14,20);
    CHECK((a/b).getNumerator() == 50);
    CHECK((a/b).getDenominator() == 21);

}

TEST_CASE("operator ++"){
    Fraction a(5,3), b(14,20);
    CHECK((++a).getNumerator() == 8);
    CHECK((++a).getDenominator() == 3);
    CHECK((++b).getNumerator() == 17);
    CHECK((++b).getDenominator() == 10);
}
TEST_CASE("operator --"){
    Fraction a(5,3), b(14,20);
    CHECK((--a).getNumerator() == 2);
    CHECK((--a).getDenominator() == 3);
    CHECK((--b).getNumerator() == -3);
    CHECK((--b).getDenominator() == 10);
}
TEST_CASE("operator >")
{
Fraction a(2,3), b(4,6);
      CHECK_FALSE(b > a); 

        Fraction c(4,5);
              CHECK_FALSE(!(c > a)); 
              CHECK_FALSE(a > c);

}

TEST_CASE("operator <")
{
     Fraction a(2,3), b(4,6);
      CHECK_FALSE(b < a); 

        Fraction c(4,5);
              CHECK_FALSE(c < a); 
              CHECK_FALSE(!(a < c));
}


TEST_CASE("operator  >=")
{
    Fraction a(2,3), b(4,6);
      CHECK_FALSE(!(b >= a)); 

        Fraction c(4,5);
              CHECK_FALSE(!(c >= a)); 
              CHECK_FALSE(a >= c); 
}


TEST_CASE("operator  <=")
{
        Fraction a(2,3), b(4,6);
      CHECK_FALSE(!(b <= a)); 

        Fraction c(4,5);
              CHECK_FALSE(c <= a); 
              CHECK_FALSE(!(a <= c)); 


}

TEST_CASE("operator  ==")
{
    Fraction a(2,3), b(4,6);
      CHECK_FALSE(!(b == a)); 
    Fraction c(4,5);

      CHECK_FALSE(c == a); 

}


TEST_CASE("operator  !=")
{
    Fraction a(2,3), b(4,6);
      CHECK_FALSE(b != a); 
    Fraction c(4,5);

      CHECK_FALSE(!(c != a)); 

}



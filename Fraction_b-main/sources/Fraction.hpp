#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;
#ifndef FRACTION_H
#define FRACTION_H
namespace ariel
{
const int TOLERANCE1 = 1000;

class Fraction {
private:
	int 	nom;
	int 	den;

public:
	// Fraction that represents a fraction of two integers
	Fraction(int numerator1, int denominator1): nom(numerator(negativeN(numerator1,denominator1),negativeD(numerator1,denominator1))), den(denominator(negativeN(numerator1,denominator1),negativeD(numerator1,denominator1))) {
		 if( numerator1 == 0 || denominator1 == 0 ){
			if(denominator1 == 0 ){
        		throw std::invalid_argument("divide by zero");
			}
    	}
	 }
	// Accepts a float number and creates a Fraction that represents a fraction of two integers
	// Constructs with a reduced fraction
	// Fraction(float nn): nom(numerator(int(nn*TOLERANCE1),TOLERANCE1)), den(denominator(int(nn*TOLERANCE1),TOLERANCE1)) { }  
// Constructs with an unreduced fraction
	Fraction(float num): nom(int(num*TOLERANCE1)), den(TOLERANCE1) { }  
	// Default constructor
	Fraction() : nom(1), den(1){ }  

	int n() const {
		return nom;
	}
	int d() const {
		return den;
	}
	
	operator string() const {             
		return to_string(nom)+"/"+to_string(den);
	}
	// The function accepts an int value and changes the value of the "nom" parameter to this value
	void setNumerator(int num) ;
	// The function accepts an int value and changes the value of the "den" parameter to this value
	void setDenominator(int sen) ;
	// The function accepts the numerator and denominator of the fraction, if the denominator is negative then it multiplies the numerator by 1-. Because a denominator cannot be negative in a fraction. For example: 1/-4 is incorrect but -1/4 is correct
	int negativeN(int num,int sen);
	// The function accepts the numerator and denominator of the fraction, if the denominator is negative then it the denominator will be the absolute value. Because a denominator cannot be negative in a fraction. For example: 1/-4 is incorrect but -1/4 is correct
	int negativeD(int num,int sen);
	// Returns the numerator of fraction
	int getNumerator();
	// Returns the denominator of fraction
	int getDenominator();  
	//Gets the numerator and denominator of fraction Returns the reduced numerator
	int numerator(int numerator1, int denominator1) const;
	//Gets the numerator and denominator of fraction Returns the reduced denominator
	int denominator(int numerator1, int denominator1) const;
	// The greatest common divisor of two numbers 
	int gcd(int num1, int num2) const;  
	// The + operator to add two fractions and return their sum as another fraction in reduced form.
	friend Fraction operator+ (const Fraction& fractionA, const Fraction& other);
	// The - operator to subtract two fractions and return their difference as another fraction in reduced form.
	friend Fraction operator- (const Fraction& fractionA, const Fraction& other);
	// The * operator to multiply two fractions and return their product as another fraction in reduced form.
	friend Fraction operator* (const Fraction& fractionA, const Fraction& other);
	// The / operator to divide two fractions and return their quotient as another fraction in reduced form.
	friend Fraction operator/ (const Fraction& fractionA, const Fraction& other);
	// The == operator to compare two fractions for equality and return true or false.
	friend bool operator== (const Fraction& fractionA, const Fraction& other);
	// The != operator to compare two fractions for unequal and return true or false.
	friend bool operator!= (const Fraction& fractionA, const Fraction& other);
	// The > operator to compare two fractions with the first fraction greater than the second fraction and return true or false.
	friend bool operator> (const Fraction& fractionA, const Fraction& other);
	// The > operator to compare two fractions with the first fraction smaller than the second fraction and return true or false.
	friend bool operator< (const Fraction& fractionA, const Fraction& other);
	// The >= operator to compare two fractions with the first fraction greater or equality than the second fraction and return true or false.
	friend bool operator>=(const Fraction& fractionA, const Fraction& other);
	// The <= operator to compare two fractions with the first fraction smaller or equality than the second fraction and return true or false.
	friend bool operator<=(const Fraction& fractionA, const Fraction& other);
	// The ++ and -- operator that adds 1 to the fraction. implement both pre and post fix.
	// In the case of x++
	friend Fraction operator++(Fraction& fractionA, int);
	// In the case of ++x
	Fraction operator++();
	// The ++ and -- operator that substracts 1 to the fraction. implement both pre and post fix.
	// In the case of x--
	friend Fraction operator--(Fraction& fractionA, int);
	// In the case of --x
	Fraction operator--();
	// The << operator to print a fraction to an output stream in the format “numerator/denominator”.
	friend ostream& operator<<(ostream& output, const Fraction& frac);
	// The >> operator to read a fraction from an input stream by taking two integers as input.
	friend istream& operator>>(istream& input, Fraction& frac);
};
#endif

}


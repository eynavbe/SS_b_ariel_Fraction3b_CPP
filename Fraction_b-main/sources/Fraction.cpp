#include "Fraction.hpp"
#include <cmath>
#include <limits>
#include <stdexcept>
using namespace std;

namespace ariel {
	int max_int = std::numeric_limits<int>::max();
	int min_int = std::numeric_limits<int>::min();

	void Fraction::setNumerator(int num) {
		nom = num;
	}

	void Fraction::setDenominator(int sen) {
		den = sen;
	}

	int Fraction::negativeD(int num,int sen){
		return abs(sen);
	}

	int Fraction::negativeN(int num,int sen){
		if(sen < 0){
			num = num * -1;
		}
		return num;
	}

	// https://www.programiz.com/cpp-programming/examples/hcf-gcd
	int Fraction:: gcd(int num1, int num2) const{
		num1 = abs(num1);
		num2 = abs(num2);
		if(num1 == 0){
			return num2;
		}
		if(num2 == 0){
			return num1;
		}
		while(num1 != num2) {
		if(num1 > num2){
			num1 -= num2;
		}
		else{
			num2 -= num1;
		}
		}
		return num1;
	}

	int Fraction::numerator(int numerator1, int denominator1) const {
		int max_int = std::numeric_limits<int>::max();
		int min_int = std::numeric_limits<int>::min();
		if(denominator1 == 0){
			return numerator1;
		}
		if(denominator1 == max_int  &&  numerator1 == max_int ){
			return 1;
		}
		if(denominator1 == min_int && numerator1 == min_int){
			return 1;
		}
		if(denominator1 == max_int || denominator1 == min_int || numerator1 == max_int || numerator1 == min_int){
			return numerator1;
		}
		int amountTimes = int(numerator1 / denominator1);

		int rest = int(numerator1 - (amountTimes*denominator1));

		return ((rest/gcd(rest,denominator1)) + (denominator(numerator1,denominator1)*amountTimes));
	}

	int Fraction::denominator(int numerator1, int denominator1) const {
		
		if(denominator1 == 0){
			return denominator1;
		}
		if(denominator1 == max_int  &&  numerator1 == max_int ){
			return 1;
		}
		if(denominator1 == min_int && numerator1 == min_int){
			return 1;
		}
		if(denominator1 == max_int || denominator1 == min_int || numerator1 == max_int || numerator1 == min_int){
			return denominator1;
		}
		int amountTimes = int(numerator1 / denominator1);

		int rest = int(numerator1 - (amountTimes*denominator1));
		return int(denominator1/gcd(rest,denominator1));
	}

	int Fraction::getNumerator(){
		return this->nom;
	}

	int Fraction::getDenominator(){
		return this->den;
	}

	Fraction operator+ (const Fraction& fractionA, const Fraction& other) {
		long add1L = (long) fractionA.n() *(long) other.d() + (long)fractionA.d() * (long)other.n();
		long add2L = (long) fractionA.d() *(long) other.d();
		if(add1L < min_int || add2L< min_int || add1L > max_int || add2L > max_int){
			throw std::overflow_error("large/small number");
		}
		int add1 = (int) add1L;
		int add2 = (int) add2L;
		return Fraction(fractionA.numerator(add1, add2),fractionA.denominator(add1, add2));
	}

	Fraction operator- (const Fraction& fractionA, const Fraction& other) {
		long sub1L =(long)  fractionA.n() *(long)  other.d() - (long) fractionA.d() * (long) other.n();
		long sub2L =(long) fractionA.d() *(long)  other.d();
		if(sub1L < min_int || sub2L< min_int || sub1L > max_int || sub2L > max_int){
			throw std::overflow_error("large/small number");
		}
		int sub1 = (int)sub1L;
		int sub2 = (int)sub2L;
		return Fraction(fractionA.numerator(sub1, sub2),fractionA.denominator(sub1, sub2));
	}

	Fraction operator* (const Fraction& fractionA, const Fraction& other) {
		long mul1L = (long)fractionA.n() * (long)other.n();
		long mul2L = (long)fractionA.d() * (long)other.d();
		if(mul1L < min_int || mul2L< min_int || mul1L > max_int || mul2L > max_int){
			throw std::overflow_error("large/small number");
		}
		int mul1 = (int)mul1L;
		int mul2 = (int)mul2L;
		return Fraction(fractionA.numerator(mul1, mul2),fractionA.denominator(mul1, mul2));
	}


	Fraction operator/ (const Fraction& fractionA, const Fraction& other) {
		if(other.n() == 0){
			throw std::runtime_error("This function threw an error!");
		}
		long div1L = (long)fractionA.n() * (long)other.d();
		long div2L = (long)fractionA.d() * (long)other.n();
		if(div1L < min_int || div2L< min_int || div1L > max_int || div2L > max_int){
			throw std::overflow_error("large/small number");
		}
		int div1 = (int)div1L;
		int div2 = (int)div2L;
		return Fraction(fractionA.numerator(div1, div2),fractionA.denominator(div1, div2));
	}

	bool operator== (const Fraction& fractionA, const Fraction& other) {
		int numerA = fractionA.n() * other.d();
		int numerO =  other.n() * fractionA.d();
		return numerA == numerO;
	}

	bool operator!= (const Fraction& fractionA, const Fraction& other) {
		return !(fractionA == other);
	}

	bool operator> (const Fraction& fractionA, const Fraction& other) {
		int numerA = fractionA.n() * other.d();
		int numerO =  other.n() * fractionA.d();
		return numerA > numerO;
	}

	bool operator< (const Fraction& fractionA, const Fraction& other) {
		int numerA = fractionA.n() * other.d();
		int numerO =  other.n() * fractionA.d();
		return numerA < numerO;
	}

	bool operator>= (const Fraction& fractionA, const Fraction& other) {
		return ((fractionA==other) || (fractionA>other));
	}

	bool operator<= (const Fraction& fractionA, const Fraction& other) {
		return ((fractionA==other) || (fractionA<other));
	}

	Fraction operator++(Fraction& fractionA, int) {
		int sum = (fractionA.n() + fractionA.d());
		Fraction fractionB = Fraction(fractionA.n(),fractionA.d());
		int nume = fractionA.numerator(sum, fractionA.d());
		int deno = fractionA.denominator(sum, fractionA.d());
		(fractionA).setNumerator(nume);
		(fractionA).setDenominator(deno);
		return fractionB;
	}

	Fraction Fraction::operator++() {
		Fraction fractionA = (*this);
		int sum = (fractionA.n() + fractionA.d());
		int nume = fractionA.numerator(sum, fractionA.d());
		int deno = fractionA.denominator(sum, fractionA.d());
		(*this).setNumerator(nume);
		(*this).setDenominator(deno);
		fractionA.setNumerator(nume);
		fractionA.setDenominator(deno);
		return fractionA;
	}

	Fraction operator--(Fraction& fractionA, int) {
	int sum = (fractionA.n() - fractionA.d());
		Fraction fractionB = Fraction(fractionA.n(),fractionA.d());
		int nume = fractionA.numerator(sum, fractionA.d());
		int deno = fractionA.denominator(sum, fractionA.d());
		(fractionA).setNumerator(nume);
		(fractionA).setDenominator(deno);
		return fractionB;
	}

	Fraction Fraction::operator--() {
		Fraction fractionA = (*this);
		int sum = (fractionA.n() - fractionA.d());
		int nume = fractionA.numerator(sum, fractionA.d());
		int deno = fractionA.denominator(sum, fractionA.d());
		(*this).setNumerator(nume);
		(*this).setDenominator(deno);
		fractionA.setNumerator(nume);
		fractionA.setDenominator(deno);
		return fractionA;
	}

	static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
		char actualChar;
		input >> actualChar;
		if (!input) {return input;}
		if (actualChar!=expectedChar) {
			input.setstate(ios::failbit);
		}
		return input;
	}


	istream& operator>>(istream& input, Fraction& frac) {
		int new_re = 0, new_im = 0;
		ios::pos_type startPosition = input.tellg();
		if ((!(input >> new_re))   ||
			(!(input >> new_im))){            
			throw std::runtime_error("This function threw an error!");
			// rewind on error
			auto errorState = input.rdstate(); // remember error state
			input.clear(); // clear error so seekg will work
			input.seekg(startPosition); // rewind
			input.clear(errorState); // set back the error flag
		} else {
			if(new_im == 0){
				throw std::runtime_error("divide by zero");
			}
			frac.setNumerator(frac.numerator(frac.negativeN(new_re,new_im),frac.negativeD(new_re,new_im)));
			frac.setDenominator(frac.denominator(frac.negativeN(new_re,new_im),frac.negativeD(new_re,new_im)));
		}
		return input;
	}

	ostream& operator<<(ostream& output, const Fraction& frac) {
		return output << frac.n() << '/' << frac.d();
	}
}


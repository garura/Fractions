/*
 ============================================================================
 File Name   : fraction.h
 Author      : Chris Jordan
 Revision History: None
 Date             Version     Change ID    Author          Comment
 07-7-15          1.0         NA           Chris Jordan    None
 ============================================================================
 
 Description : Implementation file for fraction class. An object of fraction
 class contains two int data members, numerator and denominator, and represents
 a fraction value in the form of (numerator)/(denominator).
 
 numerator and denominator are data members of type int used to represent the
 numerator and denominator, respectively, of a fraction. They will always be
 stored as the lowest possible values while maintaining the same
 fractional value. The numerator can be positive or negative, whereas the 
 denominator will always be positive.

*/

#include "fraction.h"

namespace cs2b_fraction {

    using namespace std;






    fraction::fraction(int inNumerator, int inDenominator) {
        assert(inDenominator != 0);
        numerator = inNumerator;
        denominator = inDenominator;
        this->simplify();
    }






    ostream& operator<< (ostream& out, const fraction& right) {
        if (abs(right.numerator) >= abs(right.denominator)) {
            out << right.numerator/right.denominator;
            if (right.numerator%right.denominator != 0) {
                out << "+" << abs(right.numerator%right.denominator) << "/" << right.denominator;
            }
        }
        else if (right.numerator == 0) {
            out << 0;
        }
        else {
            out << right.numerator << "/" << right.denominator;
        }
        return out;
    }






    istream& operator>> (istream& in, fraction& right) {
        int temp = 0;
        right.denominator = 1;
        in >> right.numerator;
        if (in.peek() == '+') {
            in.ignore();
            temp = right.numerator;
            in >> right.numerator;
        }
        if (in.peek() == '/') {
            in.ignore();
            in >> right.denominator;
        }
        if (temp < 0) {
            right.numerator *= -1;
        }
        right.numerator += temp*right.denominator;
        right.simplify();
        return in;
    }






    bool operator< (const fraction& left, const fraction& right) {
        return (left.numerator*right.denominator < right.numerator*left.denominator);
    }






    bool operator<= (const fraction& left, const fraction& right) {
        return (left.numerator*right.denominator <= right.numerator*left.denominator);
    }






    bool operator> (const fraction& left, const fraction& right) {
        return (left.numerator*right.denominator > right.numerator*left.denominator);
    }






    bool operator>= (const fraction& left, const fraction& right) {
        return (left.numerator*right.denominator >= right.numerator*left.denominator);
    }






    bool operator== (const fraction& left, const fraction& right) {
        return (left.numerator*right.denominator == right.numerator*left.denominator);
    }






    bool operator!= (const fraction& left, const fraction& right) {
        return (left.numerator*right.denominator != right.numerator*left.denominator);
    }






    fraction operator+ (const fraction& left, const fraction& right) {
        fraction result(left.numerator*right.denominator+
                        right.numerator*left.denominator,
                        left.denominator*right.denominator);
        return result;
    }






    fraction operator- (const fraction& left, const fraction& right) {
        fraction result(left.numerator*right.denominator -
                        right.numerator*left.denominator,
                        left.denominator*right.denominator);
        return result;
    }






    fraction operator* (const fraction& left, const fraction& right) {
        fraction result(left.numerator*right.numerator,
                        left.denominator*right.denominator);
        return result;
    }






    fraction operator/ (const fraction& left, const fraction& right) {
        fraction result(left.numerator*right.denominator,
                        left.denominator*right.numerator);
        return result;
    }






    fraction fraction::operator+=(const fraction &right) {
        *this = *this + right;
        return *this;
    }






    fraction fraction::operator-=(const fraction &right) {
        *this = *this - right;
        return *this;
    }






    fraction fraction::operator*=(const fraction &right) {
        *this = *this * right;
        return *this;
    }






    fraction fraction::operator/=(const fraction &right) {
        *this = *this / right;
        return *this;
    }






    fraction fraction::operator++ () {
        numerator += denominator;
        return *this;
    }






    fraction fraction::operator++ (int) {
        fraction temp(numerator, denominator);
        numerator += denominator;
        return temp;
    }






    fraction fraction::operator-- () {
        numerator -= denominator;
        return *this;
    }
    
    
    
    
    
    
    fraction fraction::operator-- (int) {
        fraction temp(numerator, denominator);
        numerator -= denominator;
        return temp;
    }
    
    
    
    


    void fraction::simplify() {
        if (denominator <0) {  // denominator will be positive
            numerator *= -1;
            denominator *= -1;
        }
        long i = (min(abs(numerator), abs(denominator)));
        if (i != 0) {

            // this construct allows simplify() to work whether i is prime or not
            if (numerator%i==0 && denominator%i ==0) {
                numerator /= i;
                denominator /= i;
            }
            else {
                for (long j = i/2; j>1; j--) {
                    // look for factors of i, starting at i/2
                    if (numerator%j==0 && denominator%j==0) {
                        numerator /= j;
                        denominator /= j;
                        j = (min(numerator, denominator))/2; // recursive idea
                    }
                }
            }
        }
    }
} // end namespace

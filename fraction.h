/* 
 ============================================================================
 File Name   : fraction.h
 Author      : Chris Jordan
 Revision History: None
 Date             Version     Change ID    Author          Comment
 07-7-15          1.0         NA           Chris Jordan    None
 ============================================================================

 Description : Header file for fraction class. An object of fraction class
 contains two int data members, numerator and denominator, and represents a
 fraction value in the form of (numerator)/(denominator).
 
 Public Functions:
 
 
 fraction(int inNumerator = 0, int inDenominator = 1);
 Precondition:  inNumerator is the intended numerator of the fraction.
                inDenominator is the intended denominator of the function.
 Postcondition: An object of type fraction is instantiated. numerator and 
                denominator data members will be instantiated with values 
                of 0 and 1, respectively, if respective parameter is empty.
                If numerator and denominator can be reduced to simplified
                values, the new fraction object will be made with those 
                values instead. The fraction will always represent the 
                denominator as a positive value.

 friend std::ostream& operator<<(std::ostream& out, const fraction& right);
 Precondition:  out is a valid out stream. right is a fraction.
 Postcondition: The fraction, right, is sent to the stream in the format
                of ((-)numerator"/"denominator) if the absolute value of
                the numerator is less than the denominator, (1) if numerator
                is equal to denominator, (0) if numerator is 0. If the 
                absolute value of numerator is greater than the denominator,
                the format will be an int with the value of 
                numerator/denominator, a "+" symbol, followed by numerator
                mod denominator, a "/" symbol, and denominator. Returns out.
                (e.g. -3/4, 1, 0, or 2+1/3).

 friend void operator>>(std::istream& in, fraction& right);
 Precondition:  in is a valid in stream, right is a fraction. Funtion reads
                a valid fraction format, and assigns the read value to right.
                Valid fraction format is considered to be the following:
                a mixed fraction (e.g. 2+1/4 or -3+3/4), a proper or improper
                fraction (e.g. 5/8 or -14/3), a whole number (e.g. 4 or -5),
                or 0.

 Postcondition: right numerator and denominator values will be set to the
                values that were read.

 friend bool operator< (const fraction& left, const fraction& right);
 Precondition:  left and right are fraction objects or integers.
 Postcondition: Returns a boolean representing the relation between 
                fractions left and right. If left's fractional value is less
                than right's fractional value, this function returns true. 
                Otherwise, it returns false.

 friend bool operator<= (const fraction& left, const fraction& right);
 Precondition:  left and right are fraction objects or integers.
 Postcondition: Returns a boolean representing the relation between
                fractions left and right. If left's fractional value is less
                than or equal to right's fractional value, this function
                returns true. Otherwise, it returns false.

 friend bool operator> (const fraction& left, const fraction& right);
 Precondition:  left and right are fraction objects or integers.
 Postcondition: Returns a boolean representing the relation between
                fractions left and right. If left's fractional value is greater
                than right's fractional value, this function
                returns true. Otherwise, it returns false.

 friend bool operator>= (const fraction& left, const fraction& right);
 Precondition:  left and right are fraction objects or integers.
 Postcondition: Returns a boolean representing the relation between
                fractions left and right. If left's fractional value is greater
                than or equal to right's fractional value, this function
                returns true. Otherwise, it returns false.

 friend bool operator== (const fraction& left, const fraction& right);
 Precondition:  left and right are fraction objects or integers.
 Postcondition: Returns a boolean representing the relation between
                fractions left and right. If left's fractional value is equal
                to right's fractional value, this function returns true.
                Otherwise, it returns false.

 friend bool operator!= (const fraction& left, const fraction& right);
 Precondition:  left and right are fraction objects or integers.
 Postcondition: Returns a boolean representing the relation between
                fractions left and right. If left's fractional value is not
                equal to right's fractional value, this function returns true.
                Otherwise, it returns false.

 friend fraction operator+ (const fraction& left, const fraction& right);
 Precondition:  left and right are fraction objects or integers.
 Postcondition: Returns a new fraction with numerator and denominator values
                representing the result of the left and right fractional
                summation.

 friend fraction operator- (const fraction& left, const fraction& right);
 Precondition:  left and right are fraction objects or integers.
 Postcondition: Returns a new fraction with numerator and denominator values
                representing the result of the left and right fractional
                subtraction.

 friend fraction operator* (const fraction& left, const fraction& right);
 Precondition:  left and right are fraction objects or integers.
 Postcondition: Returns a new fraction with numerator and denominator values
                representing the result of the left and right fractional
                multiplication.

 friend fraction operator/ (const fraction& left, const fraction& right);
 Precondition:  left and right are fraction objects or integers.
 Postcondition: Returns a new fraction with numerator and denominator values
                representing the result of the left and right fractional
                division.

 fraction operator+= (const fraction& right);
 Precondition:  right is a fraction object or integer.
 Postcondition: Calling fraction object uses overloaded operator+ function
                with itself and right.

 fraction operator-= (const fraction& right);
 Precondition:  right is a fraction object or integer.
 Postcondition: Calling fraction object uses overloaded operator- function
                with itself and right.

 fraction operator*= (const fraction& right);
 Precondition:  right is a fraction object or integer.
 Postcondition: Calling fraction object uses overloaded operator* function
                with itself and right.

 fraction operator/= (const fraction& right);
 Precondition:  right is a fraction object or integer.
 Postcondition: Calling object uses overloaded operator/ function with itself
                and right.

 fraction operator++ ();
 Precondition:  Calling object is of type fraction.
 Postcondition: Adds 1 to the fractional value of the caller object, then
                returns that fraction object. Prefix increment.
                (e.g. 4/5 becomes 9/5, returns 9/5).

 fraction operator++ (int);
 Precondition:  Calling object is of type fraction.
 Postcondition: Makes a copy of the calling fraction, adds 1 to the fractional
                value of the calling fraction, then returns the copy. Postfix
                increment.
                (e.g. 4/5 becomes 9/5, returns 4/5).

 fraction operator-- ();
 Precondition:  Calling object is of type fraction.
 Postcondition: Subtracts 1 from the fractional value of the calling function,
                then returns that fraction object. Prefix decrement.
                (e.g. 4/5 becomes -1/5, returns -1/5).

 fraction operator-- (int);
 Precondition:  Calling object is a fraction.
 Postcondition: Makes a copy of the calling fraction, subtracts 1 from the
                fractional value of the calling fraction, then returns the
                copy. Postfix decrement.
                (e.g. 4/5 becomes -1/5, returns 4/5).

 */


#ifndef FRACTION_H
#define FRACTION_H



#include <iostream>
#include <cassert>
#include <cmath>

namespace cs2b_fraction {

   class fraction {
   public:
      fraction(int inNumerator = 0, int inDenominator = 1);
      friend std::ostream& operator<<(std::ostream& out, const fraction& right);
      friend std::istream& operator>>(std::istream& in, fraction& right);
      friend bool operator< (const fraction& left, const fraction& right);
      friend bool operator<= (const fraction& left, const fraction& right);
      friend bool operator> (const fraction& left, const fraction& right);
      friend bool operator>= (const fraction& left, const fraction& right);
      friend bool operator== (const fraction& left, const fraction& right);
      friend bool operator!= (const fraction& left, const fraction& right);
      friend fraction operator+ (const fraction& left, const fraction& right);
      friend fraction operator- (const fraction& left, const fraction& right);
      friend fraction operator* (const fraction& left, const fraction& right);
      friend fraction operator/ (const fraction& left, const fraction& right);
      fraction operator+= (const fraction& right);
      fraction operator-= (const fraction& right);
      fraction operator*= (const fraction& right);
      fraction operator/= (const fraction& right);
      fraction operator++ ();
      fraction operator++ (int);
      fraction operator-- ();
      fraction operator-- (int);

   private:
      int numerator;
      int denominator;
      void simplify();
   };
   
} // namespace end



#endif


/* Output

 ----- Testing basic fraction creation & printing
 (fractions should be in reduced form, and as mixed numbers.)
 fraction [0] = 1/2
 fraction [1] = -5/7
 fraction [2] = 10
 fraction [3] = -4
 fraction [4] = 0
 fraction [5] = 4+2/3
 fraction [6] = 0

 ----- Now reading fractions from file
 Read fraction = 1/3
 Read fraction = 1/2
 Read fraction = 3/4
 Read fraction = -4/5
 Read fraction = 6
 Read fraction = 5
 Read fraction = -8
 Read fraction = 1+2/5
 Read fraction = -16+2/3
 Read fraction = 1+1/4
 Read fraction = 2
 Read fraction = -4+1/4
 Read fraction = -10+5/6

 ----- Testing relational operators between fractions
 Comparing 1/2 to 1/2
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false
 Comparing 1/2 to -1/2
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
 Comparing -1/2 to 1/10
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
 Comparing 1/10 to 0
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
 Comparing 0 to 0
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false

 ----- Testing relations between fractions and integers
 Comparing -1/2 to 2
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
 Comparing -3 to 1/4
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true

 ----- Testing binary arithmetic between fractions
 1/6 + 1/3 = 1/2
 1/6 - 1/3 = -1/6
 1/6 * 1/3 = 1/18
 1/6 / 1/3 = 1/2
 1/3 + -2/3 = -1/3
 1/3 - -2/3 = 1
 1/3 * -2/3 = -2/9
 1/3 / -2/3 = -1/2
 -2/3 + 5 = 4+1/3
 -2/3 - 5 = -5+2/3
 -2/3 * 5 = -3+1/3
 -2/3 / 5 = -2/15
 5 + -1+1/3 = 3+2/3
 5 - -1+1/3 = 6+1/3
 5 * -1+1/3 = -6+2/3
 5 / -1+1/3 = -3+3/4

 ----- Testing arithmetic between fractions and integers
 -1/2 + 4 = 3+1/2
 -1/2 - 4 = -4+1/2
 -1/2 * 4 = -2
 -1/2 / 4 = -1/8
 3 + -1/2 = 2+1/2
 3 - -1/2 = 3+1/2
 3 * -1/2 = -1+1/2
 3 / -1/2 = -6

 ----- Testing shorthand arithmetic assignment on fractions
 1/6 += 4 = 4+1/6
 4+1/6 -= 4 = 1/6
 1/6 *= 4 = 2/3
 2/3 /= 4 = 1/6
 4 += -1/2 = 3+1/2
 3+1/2 -= -1/2 = 4
 4 *= -1/2 = -2
 -2 /= -1/2 = 4
 -1/2 += 5 = 4+1/2
 4+1/2 -= 5 = -1/2
 -1/2 *= 5 = -2+1/2
 -2+1/2 /= 5 = -1/2

 ----- Testing shorthand arithmetic assignment using integers
 -1/3 += 3 = 2+2/3
 2+2/3 -= 3 = -1/3
 -1/3 *= 3 = -1
 -1 /= 3 = -1/3

 ----- Testing increment/decrement prefix and postfix
 Now g = -1/3
 g++ = -1/3
 Now g = 2/3
 ++g = 1+2/3
 Now g = 1+2/3
 g-- = 1+2/3
 Now g = 2/3
 --g = -1/3
 Now g = -1/3
 
 */

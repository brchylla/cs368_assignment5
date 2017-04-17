///////////////////////////////////////////////////////////////////////////////
// File Name:      SmartInteger.hpp
//
// Author:         Ben Chylla, Roz Stengle
// CS email:       chylla@cs.wisc.edu, stengle@cs.wisc.edu
//
// Description:    The implementation of the SmartInteger class.
///////////////////////////////////////////////////////////////////////////////

#ifndef A5_SMARTINTEGER_HPP
#define A5_SMARTINTEGER_HPP

#include <limits.h>
#include <stdio.h>


class SmartInteger {
	private:
		// the sole member variable of SmartInteger
		int num;

	public:
		/**
		 * @brief A default constructor for SmartInteger (default value: 0)
		 *
		 */
		SmartInteger::SmartInteger(){
			num = 0;
		}

		/**
		 * @brief Parameterized constructor that sets starting integer value
		 *
		 */
		SmartInteger::SmartInteger(int n){
			num = n;
		}

		/**
		 * @brief Getter for the integer value of the SmartInteger
		 *
		 * @return The integer value of the SmartInteger
		 */
		int SmartInteger::getValue(){
			return num;
		}

		/**
		 * @brief Displays integer value as if calling getValue()
		 *
		 */
		void SmartInteger::operator<<(){
			std::cout << getValue();
		}
		/**
		 * @brief Determines whether or not value of one SmartInteger is less
		 * than another
		 *
		 * @return Boolean for whether first SmartInteger is less than second
		 */
		friend bool operator<(SmartInteger first, SmartInteger second){
			if (first.getValue() < second.getValue())
				return true;
			return false;

			//what should it do if one or both of them exceeds 4 bits?
		}
		/**
		 * @brief Determines whether or not value of first SmartInteger is
		 *  greater than second
		 *
		 * @return Boolean for whether first SmartInteger is greater than
		 * second
		 */
		friend bool operator>(SmartInteger first, SmartInteger second);

		/**
		 * @brief Determines whether or not value of first SmartInteger is
		 * less than or equal to second SmartInteger
		 *
		 * @return Boolean for whether first SmartInteger is less than or
		 * equal to second SmartInteger
		 */
		friend bool operator<=(SmartInteger first, SmartInteger second){
			if (first.getValue() >= second.getValue()){
				return true;
			}
			return false;
		}
		
		/**
		 * @brief Determines whether or not value of first SmartInteger is
		 * greater than or equal to second SmartInteger
		 *
		 * @return Boolean for whether first SmartInteger is greater than or
		 * equal to second SmartInteger
		 */
		friend bool operator>=(SmartInteger first, SmartInteger second);

		/**
		 * @brief Determines whether or not first SmartInteger is equal to
		 * second SmartInteger
		 *
		 * @return Boolean for whether first SmartInteger is equal to second
		 * SmartInteger
		 */
		friend bool operator==(SmartInteger first, SmartInteger second){
			if (first.gerValue() == second.getValue())
				return true;
			return false;
		}
	
		/**
		 * @brief Determines whether or not first SmartInteger is NOT equal to
		 * second SmartInteger
		 *
		 * @return Boolean for whether first SmartInteger is equal to second
		 * SmartInteger
		 */
		friend bool operator!=(SmartInteger first, SmartInteger second);

		/**
		 * @brief Adds first SmartInteger to second to calculate sum
		 *
		 * @return The sum of the SmartIntegers
		 */
		friend SmartInteger operator+(SmartInteger first, SmartInteger second){
			if(abs(first.gerValue()) > abs(INT_MAX - second.getValue())) {
				throw exception;
			}
			
			if(abs(second.gerValue()) > abs(INT_MAX - first.getValue())) {
				throw exception;
			}
			
			return first.getValue() + second.getValue();
		}

		/**
		 * @brief Subtracts second SmartInteger from first to calculate
		 * difference
		 *
		 * @return The difference of the two SmartIntegers
		 */
		friend SmartInteger operator-(SmartInteger first, SmartInteger second);

		/**
		 * @brief Multiplies first and second SmartIntegers to calculate
		 * product
		 *
		 * @return The product of the two SmartIntegers
		 */
		friend SmartInteger operator*(SmartInteger first, SmartInteger second) {
			if (abs(INT_MAX/frist.getValue() > second.getValue()))
				|| abs(INT_MAX/second.getValue() < first.getValue())) {
				throw exception;
			}
			return first.getValue() * second.gerValue();
		}

		/**
		 * @brief Adds second SmartInteger to first SmartInteger
		 *
		 * @return New value of first SmartInteger after adding second
		 * SmartInteger
		 */
		friend SmartInteger operator+=(SmartInteger first, SmartInteger second);

		/**
		 * @brief Subtracts second SmartInteger from first SmartInteger
		 *
		 * @return New value of first SmartInteger after subtracting second
		 * SmartInteger
		 */
		friend SmartInteger operator-=(SmartInteger first, SmartInteger second){
		if (abs(INT_MAX - first.getValue() > second.getValue())) ||
			(abs(INT_MAX - secnod.getValue() > first.getValue())) {
				throw exception;
				}
		return first.getValue() - second.getValue();
		}

		/**
		 * @brief Multiplies first SmartInteger by second SmartInteger
		 *
		 * @return New value of first SmartInteger after multiplying by second
		 * SmartInteger
		 */
		friend SmartInteger operator*=(SmartInteger first, SmartInteger second) {
			
		}

		/**
		 * @brief Negates SmartInteger
		 *
		 * @return Negated version of original SmartInteger
		 */
		SmartInteger operator-(SmartInteger num) {
			if (abs(INT_MAX - this->num > num) || (INT_MAX - num > this->num) {
				throw exception;
			}
			return this->num - num;
		}

		/**
		 * @brief Increments current SmartInteger
		 *
		 * @return The incremented SmartInteger
		 */
		SmartInteger operator++(SmartInteger num);

		/**
		 * @brief Decrements current SmartInteger
		 *
		 * @return The decremented SmartInteger
		 */
		SmartInteger operator--(SmartInteger num) {
			if (num.getValue() < 0) && (INT_MIN -1 == num.getValue()) {
				throw exception;
			}
			num.getValue() = num.get() - 1;
			return num.get();
		}

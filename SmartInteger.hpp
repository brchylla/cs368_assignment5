///////////////////////////////////////////////////////////////////////////////
// File Name:      SmartInteger.hpp
//
// Author:         Ben Chylla, Roz Stengle
// CS email:       chylla@cs.wisc.edu, stengle@cs.wisc.edu
//
// Description:    The header file for the SmartInteger class.
///////////////////////////////////////////////////////////////////////////////

#ifndef A5_SMARTINTEGER_HPP
#define A5_SMARTINTEGER_HPP

#include <limits.h>
#include <exception>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class SmartInteger {
	private:
		// the sole member variable of SmartInteger
		int num;

	public:
		/**
		 * @brief A default constructor for SmartInteger (default value: 0)
		 *
		 */
		SmartInteger();

		/**
		 * @brief Parameterized constructor that sets starting integer value
		 *
		 */
		SmartInteger(int num);

		/**
		 * @brief Getter for the integer value of the SmartInteger
		 *
		 * @return The integer value of the SmartInteger
		 */
		const int getValue() const;

		/**
		 * @brief Displays integer value as if calling getValue()
		 *
		 */
		friend std::ostream& operator<<(std::ostream& out, const SmartInteger& num);

		/**
		 * @brief Determines whether or not value of one SmartInteger is less
		 * than another
		 *
		 * @return Boolean for whether first SmartInteger is less than second
		 */
		const friend bool operator<(const SmartInteger first, const SmartInteger second);

		/**
		 * @brief Determines whether or not value of first SmartInteger is
		 *  greater than second
		 *
		 * @return Boolean for whether first SmartInteger is greater than
		 * second
		 */
		const friend bool operator>(const SmartInteger first, const SmartInteger second);

		/**
		 * @brief Determines whether or not value of first SmartInteger is
		 * less than or equal to second SmartInteger
		 *
		 * @return Boolean for whether first SmartInteger is less than or
		 * equal to second SmartInteger
		 */
		const friend bool operator<=(const SmartInteger first, const SmartInteger second);

		/**
		 * @brief Determines whether or not value of first SmartInteger is
		 * greater than or equal to second SmartInteger
		 *
		 * @return Boolean for whether first SmartInteger is greater than or
		 * equal to second SmartInteger
		 */
		const friend bool operator>=(const SmartInteger first, const SmartInteger second);

		/**
		 * @brief Determines whether or not first SmartInteger is equal to
		 * second SmartInteger
		 *
		 * @return Boolean for whether first SmartInteger is equal to second
		 * SmartInteger
		 */
		const friend bool operator==(const SmartInteger first, const SmartInteger second);

		/**
		 * @brief Determines whether or not first SmartInteger is NOT equal to
		 * second SmartInteger
		 *
		 * @return Boolean for whether first SmartInteger is equal to second
		 * SmartInteger
		 */
		const friend bool operator!=(const SmartInteger first, const SmartInteger second);

		/**
		 * @brief Adds first SmartInteger to second to calculate sum
		 *
		 * @return The sum of the SmartIntegers
		 */
		friend SmartInteger operator+(const SmartInteger first, const SmartInteger second);

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
		friend SmartInteger operator*(SmartInteger first, SmartInteger second);

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
		friend SmartInteger operator-=(SmartInteger first, SmartInteger second);

		/**
		 * @brief Multiplies first SmartInteger by second SmartInteger
		 *
		 * @return New value of first SmartInteger after multiplying by second
		 * SmartInteger
		 */
		friend SmartInteger operator*=(SmartInteger first, SmartInteger second);

		/**
		 * @brief Negates SmartInteger
		 *
		 * @return Negated version of original SmartInteger
		 */
		SmartInteger operator-() const;

		/**
		 * @brief Increments current SmartInteger
		 *
		 * @return The incremented SmartInteger
		 */
		SmartInteger operator++();

		/**
		 * @brief Decrements current SmartInteger
		 *
		 * @return The decremented SmartInteger
		 */
		SmartInteger operator--();


};

#endif //A5_SMARTINTEGER_HPP

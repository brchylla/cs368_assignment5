///////////////////////////////////////////////////////////////////////////////
// File Name:      SmartInteger.hpp
//
// Author:         Ben Chylla, Roz Stengle
// CS email:       chylla@cs.wisc.edu, stengle@cs.wisc.edu
//
// Description:    The body file for the SmartInteger class.
///////////////////////////////////////////////////////////////////////////////

#include "SmartInteger.hpp"

#include <limits>
#include <stdio.h>

using namespace std;

int MAX_INT = numeric_limits<int>::max();
int MIN_INT = numeric_limits<int>::min();

SmartInteger::SmartInteger(){
	this->num = 0;
}

SmartInteger::SmartInteger(int num) {
	this->num = num;
}

int SmartInteger::getValue() {
	return this->num;
}

void SmartInteger::operator<<() {
	cout << getValue() << endl;
}

friend bool operator<(SmartInteger first, SmartInteger second) {
	// let Roz implement this
}

friend bool operator>(SmartInteger first, SmartInteger second) {
	if (first.getValue() > second.getValue()) {
		return true;
	}
	return false;
}

friend bool operator<=(SmartInteger first, SmartInteger second) {
	// let Roz implement this
}

friend bool operator>=(SmartInteger first, SmartInteger second) {
	if (first.getValue() >= second.getValue()) {
		return true;
	}numeric_limits<int>::max();
	return false;
}

friend bool operator==(SmartInteger first, SmartInteger second) {
	// let Roz implement this
}

friend bool operator!=(SmartInteger first, SmartInteger second) {
	if (first.getValue() != second.getValue()) {
		return true;
	}
	return false;
}

friend SmartInteger operator+(SmartInteger first, SmartInteger second) {
	// let Roz implement this
}

friend SmartInteger operator-(SmartInteger first, SmartInteger second) {
	if ((first.getValue() < 0) &&
			(second.getValue() > INT_MAX + first.getValue())) {
		/* `first SmartInteger - second SmartInteger` would overflow */
		throw exception;
	}
	if ((first.getValue() > 0) &&
			(second.getValue() < INT_MIN + first.getValue())) {
		/* `first SmartInteger - second SmartInteger` would underflow */
		throw exception;
	}
	return first.getValue() - second.getValue();
}

friend SmartInteger operator*(SmartInteger first, SmartInteger second) {
	// let Roz implement this one
}

friend SmartInteger operator+=(SmartInteger first, SmartInteger second) {
	if ((first.getValue() > 0) &&
			(first.getValue() > INT_MAX - second.getValue())){
		/* `first SmartInteger + second SmartInteger` would overflow */;
		throw exception;
	}
	if ((second.getValue() < 0) &&
			(first.getValue() < INT_MIN - second.getValue())) {
		/* `first SmartInteger + second SmartInteger` would underflow */
		throw exception;
	}
	first.num = first.getValue() + second.getValue();
	return first.getValue();
}

friend SmartInteger operator-=(SmartInteger first, SmartInteger second) {
	// let Roz implement this one
}

friend SmartInteger operator*=(SmartInteger first, SmartInteger second) {
	if (first.getValue() > INT_MAX / first.getValue()) {
		/* `first SmartInteger * second SmartInteger` would overflow */
		throw exception;
	}
	if ((second.getValue() < INT_MIN / second.getValue())) {
		/* `first SmartInteger * second SmartInteger` would underflow */
		throw exception;
	}
	// there may be need to check for -1 for two's complement machines
	if ((first.getValue() == -1) && (second.getValue() == INT_MIN)) {
		/* `first SmartInteger * second SmartInteger` can overflow */
		throw exception;
	}
	if ((second.getValue() == -1) && (first.getValue() == INT_MIN)) {
		/* `first SmartInteger * second SmartInteger`
		 *  (or `first SmartInteger / second SmartInteger`) can overflow */
		throw exception;
	}
	first.num = first.getValue() * second.getValue();
	return first.getValue();
}

SmartInteger operator-(SmartInteger num) {
	// let Roz implement this one
}

SmartInteger operator++(SmartInteger num) {
	if ((num.getValue() > 0) &&
			(num.getValue() > INT_MAX - 1)){
		/* `SmartInteger + 1` would overflow */;
		throw exception;
	}
	if (num.getValue() < INT_MIN - 1) {
		/* `SmartInteger + 1` would underflow */
		throw exception;
	}
	num.num = num.getValue() + 1;
	return num.getValue();
}

SmartInteger operator--(SmartInteger num) {
	// let Roz implement this one
}

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
#include <exception>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAX_INT = numeric_limits<int>::max();
const int MIN_INT = numeric_limits<int>::min();

SmartInteger::SmartInteger(){
	this->num = 0;
}

SmartInteger::SmartInteger(int num) {
	this->num = num;
}

const int SmartInteger::getValue() const {
	return this->num;
}

std::ostream& operator<<(std::ostream& out, const SmartInteger& num) {
	return out << num.getValue();
}

const bool operator<(const SmartInteger first, const SmartInteger second) {
	if (first.getValue() < second.getValue()) {
		return true;
	}
	return false;
	//what should it do if one or both of them exceeds 4 bytes?
}

const bool operator>(const SmartInteger first, const SmartInteger second) {
	if (first.getValue() > second.getValue()) {
		return true;
	}
	return false;
}

const bool operator<=(const SmartInteger first, const SmartInteger second) {
	if (first.getValue() <= second.getValue()) {
		return true;
	}
	return false;
}

const bool operator>=(const SmartInteger first, const SmartInteger second) {
	if (first.getValue() >= second.getValue()) {
		return true;
	}
	return false;
}

const bool operator==(const SmartInteger first, const SmartInteger second) {
	if (first.getValue() == second.getValue()) {
		return true;
	}
	return false;
}

const bool operator!=(const SmartInteger first, const SmartInteger second) {
	if (first.getValue() != second.getValue()) {
		return true;
	}
	return false;
}

SmartInteger operator+(const SmartInteger first, const SmartInteger second) {
	if ((second.getValue() > 0) &&
			(second.getValue() > INT_MAX - first.getValue())) {
		/* `first SmartInteger - second SmartInteger` would overflow */
		throw exception();
	}
	else if ((second.getValue() < 0) &&
			(second.getValue() < INT_MIN - first.getValue())) {
		/* `first SmartInteger - second SmartInteger` would underflow */
		throw exception();
	}
	SmartInteger sum(first.getValue() + second.getValue());
	return sum;
}

SmartInteger operator-(SmartInteger first, SmartInteger second) {
	if ((second.getValue() < 0) &&
			(second.getValue() > INT_MAX + first.getValue())) {
		/* `first SmartInteger - second SmartInteger` would overflow */
		throw exception();
	}
	if ((second.getValue() > 0) &&
			(second.getValue() < INT_MIN + first.getValue())) {
		/* `first SmartInteger - second SmartInteger` would underflow */
		throw exception();
	}
	SmartInteger difference(first.getValue() - second.getValue());
	return difference;
}

SmartInteger operator*(SmartInteger first, SmartInteger second) {
	if ((abs(INT_MAX/first.getValue()) > abs(second.getValue()))
			|| (abs(INT_MAX/second.getValue()) < abs(first.getValue()))) {
		throw exception();
	}
	SmartInteger product(first.getValue() * second.getValue());
	return product;
}

SmartInteger operator+=(SmartInteger first, SmartInteger second) {
	if ((second.getValue() > 0) &&
			(first.getValue() > INT_MAX - second.getValue())){
		/* `first SmartInteger + second SmartInteger` would overflow */
		throw exception();
	}
	if ((second.getValue() < 0) &&
			(first.getValue() < INT_MIN - second.getValue())) {
		/* `first SmartInteger + second SmartInteger` would underflow */
		throw exception();
	}
	first.num = first.getValue() + second.getValue();
	return first;
}

SmartInteger operator-=(SmartInteger first, SmartInteger second) {
	if ((second.getValue() < 0) &&
			(first.getValue() > INT_MAX + second.getValue())){
		/* `first SmartInteger + second SmartInteger` would overflow */
		throw exception();
	}
	if ((second.getValue() > 0) &&
			(first.getValue() < INT_MIN + second.getValue())) {
		/* `first SmartInteger + second SmartInteger` would underflow */
		throw exception();
	}
	first.num = first.getValue() - second.getValue();
	return first;
}

SmartInteger operator*=(SmartInteger first, SmartInteger second) {
	if (first.getValue() > INT_MAX / second.getValue()) {
		/* `first SmartInteger * second SmartInteger` would overflow */
		throw exception();
	}
	if ((first.getValue() < INT_MIN / second.getValue())) {
		/* `first SmartInteger * second SmartInteger` would underflow */
		throw exception();
	}
	// there may be need to check for -1 for two's complement machines
	if ((first.getValue() == -1) && (second.getValue() == INT_MIN)) {
		/* `first SmartInteger * second SmartInteger` can overflow */
		throw exception();
	}
	if ((second.getValue() == -1) && (first.getValue() == INT_MIN)) {
		/* `first SmartInteger * second SmartInteger`
		 *  (or `first SmartInteger / second SmartInteger`) can overflow */
		throw exception();
	}
	first.num = first.getValue() * second.getValue();
	return first;
}

SmartInteger SmartInteger::operator-() const {
	if (this->getValue() == INT_MIN) {
		throw exception();
	}
	return 0 - this->getValue();
}

SmartInteger SmartInteger::operator++() {
	if ((this->getValue() > 0) &&
			(this->getValue() >= INT_MAX)) {
		/* `SmartInteger + 1` would overflow */
		throw exception();
	}
	//int newVal = this->getValue() + 1;
	//cout << "New value: " << newVal << endl;
	//SmartInteger inc(newVal);
	//cout << inc.getValue() << endl;
	return SmartInteger(this->getValue() + 1);
}

SmartInteger SmartInteger::operator--() {
	if ((this->getValue() < 0) &&
			(this->getValue() <= INT_MIN)){
		/* `SmartInteger - 1` would overflow */
		throw exception();
	}
	//int newVal = this->getValue() - 1;
	//cout << "New value: " << newVal << endl;
	//SmartInteger dec(newVal);
	//cout << dec.getValue() << endl;
	return SmartInteger(this->getValue() - 1);
}

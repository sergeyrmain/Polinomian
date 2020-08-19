#include "rational.h"
#include <iostream>
using namespace std;

const char* line = "--------------------------";


rational::rational() :_p1(), _p2() {
	_p2.setCoeff(0, 1);
}

rational::rational(const Polynomial& p1, const Polynomial& p2) : _p1(p1), _p2(p2) {

}

rational::~rational() {

}

void rational::print()const {
	cout << _p1 << line << endl << _p2;
}


Polynomial rational::getNom()const {
	return _p1;
}

Polynomial rational::getDenom()const {
	return _p2;

}

ostream& operator<<(ostream& os, const rational& ration) {
	os << ration._p1 << line << endl << ration._p2;
	return os;
}

rational rational::operator*(const rational& other)const {
	return rational(other._p1 * this->_p1, other._p2 * this->_p2);
}

rational rational::operator+(const rational& other)const
{
	Polynomial nom = this->_p1 * other._p2 + other._p1 * this->_p2;
	Polynomial denom = this->_p2 * other._p2;
	return rational(nom,denom);
} 

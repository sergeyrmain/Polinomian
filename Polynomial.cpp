#include "Polynomial.h"
#include <algorithm>
#include <iostream>

using namespace std;

int Polynomial::_maxDegree = 0;

Polynomial::Polynomial(const double* polinom, int degree) :_polinom(new double[degree + 1]), _degree(degree) {
	copy_n(polinom, degree + 1, _polinom);
	updateMaxDegree();
}


Polynomial::Polynomial() : _polinom(new double[1]), _degree(0) {
	_polinom[0] = 0.0;
}
Polynomial::Polynomial(int degree) : _polinom(new double[degree + 1]), _degree(degree) {
	fill_n(_polinom, degree + 1, 0.0);
	updateMaxDegree();
}
Polynomial::Polynomial(const Polynomial& p) : Polynomial(p._polinom, p._degree)
{
}

Polynomial::~Polynomial() {
	delete[] _polinom;
}

int Polynomial::getMaxDegree() {
	return _maxDegree;
}

void Polynomial::setCoeff(int degree, double value) {
	if (degree > this->_degree) {
		throw "degree is out of range";
	}
	_polinom[degree] = value;
	updateMaxDegree();
}

void Polynomial::updateMaxDegree() const
{
	_maxDegree = max(_maxDegree, getDegree(true));
}

int Polynomial::getDegree(bool b)const {
	if (!b)
	{
		return _degree;
	}
	else
	{
		int i = _degree;

		while (i >= 0 && abs(_polinom[i] - 0.0) <= 0.000001)
		{
			i--;
		}

		return i;
	}
}

ostream& operator<<(ostream& os, const Polynomial& poly)
{
	int j = 0, i;
	for (i = 0; i < poly._degree + 1; i++) {
		if (poly._polinom[i] != 0) j = 0;
		else j++;
	}
	os << "polynomial = ";
	os << poly._polinom[0];
	for (i = 1; i < poly._degree + 1 - j; i++)
	{
		os << "+(" << poly._polinom[i] << ")*" << "X^" << i;
	}
	os << endl;
	return os;
}
Polynomial Polynomial::operator *(const Polynomial& other) const {
	int thisMaxDegree = getDegree(true);
	int otherMaxDegree = other.getDegree(true);
	int newDegree = thisMaxDegree + otherMaxDegree;
	Polynomial newPolinom(newDegree);

	for (int i = 0; i <= thisMaxDegree; i++)
	{
		for (int j = 0; j <= otherMaxDegree; j++)
		{
			newPolinom._polinom[i + j] += (this->_polinom[i] * other._polinom[j]);
		}
	}

	return newPolinom;
}


Polynomial 	Polynomial::operator*(double num) const {
	return *this * Polynomial(&num, 0);
}

Polynomial operator*(double num, const Polynomial& poli)
{
	return poli * num;
}

Polynomial Polynomial::operator+(const Polynomial& other)const
{
	int thisMaxDegree = getDegree(true);
	int otherMaxDegree = other.getDegree(true);
	int getMaxDegree = max(thisMaxDegree, otherMaxDegree);

	Polynomial newPoli(getMaxDegree);

	for (int i = 0; i <= thisMaxDegree; i++)
	{
		newPoli.setCoeff(i, newPoli[i] + (*this)[i]);
	}
	for (int i = 0; i <= otherMaxDegree; i++)
	{
		newPoli.setCoeff(i, newPoli[i] + other[i]);
	}

	return newPoli;
}

Polynomial Polynomial::operator-(const Polynomial& other) const
{
	return *this + other * -1;
}

Polynomial& Polynomial::operator=(const Polynomial& other)
{


	fill_n(_polinom, _degree + 1, 0.0);
	copy_n(other._polinom, other._degree + 1, _polinom);

	return *this;
}

const double& Polynomial::operator[](int degree) const
{
	return _polinom[degree];
}

#pragma once
#include <iostream>
using namespace std;

class Polynomial
{
private:
	double* _polinom;
	const int _degree;
	static int _maxDegree;
public:
	Polynomial(const double* polinom, int degree);
	~Polynomial();
	Polynomial();
	Polynomial(const Polynomial& p);
	Polynomial(int degree);
	static int getMaxDegree();
	void updateMaxDegree() const;
	void setCoeff(int degree, double value);
	int getDegree(bool b)const;
	Polynomial operator *(const Polynomial& other)const;
	Polynomial operator*(double num) const;
	Polynomial operator+(const Polynomial& other)const;
	Polynomial operator-(const Polynomial& other)const;
	Polynomial& operator=(const Polynomial& other);
	const double& operator[](int degree) const;
	friend ostream& operator<<(ostream& os, const Polynomial& poly);
	friend	Polynomial operator*(double num,const Polynomial& poli) ;
};

ostream& operator<<(ostream& os, const Polynomial& poly);
Polynomial operator*(double num, const Polynomial& poli);
#pragma once
#include "Polynomial.h"
class rational
{
private:
	Polynomial _p1;
	Polynomial _p2;
public:
	rational();
	~rational();
	rational(const Polynomial& p1, const Polynomial& p2);
	friend ostream& operator<<(ostream& os, const rational& ration);
	void print()const;
	rational operator*(const rational& other)const;
	rational operator+(const rational& other)const;
	Polynomial getNom()const;
	Polynomial getDenom()const;
};

ostream& operator<<(ostream& os, const rational& ration);


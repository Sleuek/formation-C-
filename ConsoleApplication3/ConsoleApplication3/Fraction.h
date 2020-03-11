#pragma once

#include <iostream>

class Fraction
{
	friend Fraction operator+(Fraction& a, Fraction& b);
	friend Fraction operator-(Fraction& a, Fraction& b);
	friend Fraction operator*(Fraction& a, Fraction& b);
	friend Fraction operator/(Fraction& a, Fraction& b);
	friend bool operator==(Fraction& a, Fraction& b);
	friend std::ostream& operator<<(std::ostream& os, const Fraction &a);
	friend std::istream& operator>>(std::istream& in, const Fraction& a);

private:
	int m_num;
	int m_den;
	void normalise();

public:
	Fraction();
	Fraction(int a);
	Fraction(int num, int den);
	void display();

};


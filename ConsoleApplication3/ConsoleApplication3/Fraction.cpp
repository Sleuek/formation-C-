#include "Fraction.h"


Fraction::Fraction()
	:m_num(1), m_den(1)
{
}

Fraction::Fraction(int a)
	: m_num(a), m_den(1)
{
}
Fraction::Fraction(int num, int den)
	: m_num(num), m_den(den)
{
	normalise();
}



std::ostream& operator<<(std::ostream& os, const Fraction &a) 
{
	os << a.m_num << "/" << a.m_den;
	return os;
}

std::istream& operator>>(std::istream& in, const Fraction& a)
{
	std::cout << "\nEnter num : ";
	in >> a.m_num;
	std::cout << "Enter den : ";
	in >> a.m_den;
	std::cout << a.m_num << " / " << a.m_den;
	return in;
}

void Fraction::display() 
{
	normalise();
	std::cout << m_num << "/" << m_num << std::endl;
}


 Fraction operator+(Fraction &a, Fraction &b) 
 {
	 a.normalise();
	 b.normalise();
	 Fraction r;
	 r.m_num = a.m_den * b.m_num + b.m_den * a.m_num;
	 r.m_den = a.m_den * b.m_den;
	 return r;
}

 Fraction operator-(Fraction& a, Fraction& b) 
{
	 a.normalise();
	 b.normalise();
	 Fraction r;
	 r.m_num = a.m_den * b.m_num - b.m_den * a.m_num;
	 r.m_den = a.m_den * b.m_den;
	 return r;
}
 Fraction operator*(Fraction& a, Fraction& b)
{
	 a.normalise();
	 b.normalise();
	 Fraction r;
	 r.m_num = b.m_num * a.m_num;
	 r.m_den = a.m_den * b.m_den;
	 return r;
}

 Fraction operator/(Fraction& a, Fraction& b)
 {
	 Fraction i;
	 i.m_den = b.m_num;
	 i.m_num = b.m_den;
	 return operator*(a, i);
}

 bool operator==(Fraction &a, Fraction &b) 
 {
	 a.normalise();
	 b.normalise();
	 return(a.m_num == b.m_num && a.m_den == b.m_den);
 }


 void Fraction::normalise() 
 {
	 int a = m_num;
	 int b = m_den;
	 if (a == 0)
	 {
		 m_num /= b;
		 m_den /= b;
	 }else {
		 while (a != b)
		 {
			 if (a > b)
			 {
				 a -= b;
			 }
			 else
			 {
				 b -= a;
			 }
		 }
		 m_num /= b;
		 m_den /= b;
	 }
	
 }
 

 
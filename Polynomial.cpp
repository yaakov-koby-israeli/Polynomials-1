#include "Polynomial.h"
#include <iostream>

int Polynomial::MaxDegree = 0;

Polynomial::Polynomial(int degree)
{
	this->degree = degree;
	this->Coeff = new double[degree+1]();
	int i;
	for (i = 0; i <= degree; i++)
		Coeff[i] = 0;
}

Polynomial::Polynomial(double* ptr, int degree)
{
	this->degree = degree;
	Coeff = new double[degree + 1];

	for (int i = 0; i <= degree; i++)
	{
		Coeff[i] = ptr[i];
		if (ptr[i] && i > MaxDegree)
			MaxDegree = i;
	}	
}
Polynomial::Polynomial(const Polynomial& p)
{
	degree = p.degree;
	if (!p.Coeff) Coeff = NULL;
	else
	{
		Coeff = new double[degree + 1];
		int i;
		for (i = 0; i <= degree; i++)
			Coeff[i] = p.Coeff[i];
	}
}


Polynomial::~Polynomial()
{
	/*if (Coeff)
	{
		delete[]Coeff;
		Coeff = NULL;
	}*/
}

int Polynomial::getMaxDegree()
{
	return MaxDegree;
}

int Polynomial::getDegree(bool what) const
{
	int i,value=0;
	if (what)
	{
		for (i = 0; i <= degree; i++)
		{
			if (Coeff[i])
				value = i;
		}
		return value;
	}
	else return degree;

}

Polynomial &Polynomial::setCoeff(int degree, double num)
{
	Coeff[degree] = num;
	return *this;
}

double Polynomial::getCoeff(int index) const
{
	if (index<0 || index>degree) return -12345.5;
	return this->Coeff[index];	
}

void Polynomial::print()const
{
	cout << "polynomial = ";
	if (!Coeff && !degree) {
		cout << "0" << endl;
		return;
	}
	int i, max = 0;
	for (i = 0; i <= degree; i++) {
		if (Coeff[i] && i > max)
			max = i;
	}
	for (i = 0; i <= max; i++) {
		if (i == 0) {
			if (!Coeff[i])
				cout << "0";
			else
				cout << Coeff[i];
		}
		else {
			cout << "+";
			if (!Coeff[i])
				cout << "0";
			else
				cout << Coeff[i];
			cout << "X^" << i;
		}
	}
	cout << endl;
}


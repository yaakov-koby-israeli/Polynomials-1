#include <iostream>
#include "Rational.h"

Rational::Rational()
{
	denom.setCoeff(0, 1);
}

Rational::Rational(const Polynomial& nom1, const Polynomial& denom1):nom(nom1),denom(denom1)
{

}

Polynomial& Rational::getNom()
{
	return nom;
}

Polynomial& Rational::getDenom()
{
	return denom;
}

void Rational::print()
{
	nom.print();
	cout << "--------------------" << endl;
	denom.print();
}

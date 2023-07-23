#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
using namespace std;

class Polynomial
{
private:

	double* Coeff;
	int degree;	
	static int MaxDegree;

public:

	Polynomial(int degree=0);
	Polynomial(double* Coeff, int degree=0);
	Polynomial(const Polynomial&p);
	~Polynomial();

	static int getMaxDegree();
	int getDegree(bool what) const;
	
	Polynomial& setCoeff(int degree, double num);
	double getCoeff(int index)const;
	void print()const;

};

#endif


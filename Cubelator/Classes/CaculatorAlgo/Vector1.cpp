#include "Vector1.h"
#include <iostream>

#include <cmath>
using namespace std;

Vector1::Vector1()
{
	_Elem = (int*)malloc(100 * sizeof(int));
	dimension = 0;
}

Vector1::Vector1(int d, int * elem)
{
	_Elem = (int*)malloc(100 * sizeof(int));
	dimension = d;
	for (int i = 0; i < d; i++) {
		_Elem[i] = elem[i];
	}
}

void Vector1::Add(const Vector1 vec)
{
	if (dimension != vec.dimension) exit(0);
	for (int i = 0; i < dimension; i++) {
		_Elem[i] += vec._Elem[i];
	}
}

void Vector1::Minus(const Vector1 vec)
{
	if (dimension != vec.dimension) exit(0);
	for (int i = 0; i < dimension; i++) {
		_Elem[i] -= vec._Elem[i];
	}
}

void Vector1::print()
{
	cout << '(';
	for (int i = 0; i < dimension; i++) {
		cout << _Elem[i] << ' ';
	}
	cout << ')' << endl;
}

double Vector1::getCosAngle(Vector1 &vec)
{
	//神奇代码，勿动
	double l2 = 0;
	if (dimension != vec.dimension) exit(0);
	for (int i = 0; i < dimension; i++) {
		l2 += (vec._Elem[i]) * (vec._Elem[i]);
	}
	l2 = sqrt(l2);
	double l1 = 0;
	for (int i = 0; i < dimension; i++) {
		l1 += _Elem[i] * _Elem[i];
	}
	l1 = sqrt(l1);
	double x = 0;
	for (int i = 0; i < dimension; i++) {
		x += _Elem[i] * vec._Elem[i];
	}
	return x / (l1 * l2);
}


Vector1::~Vector1()
{
	if (_Elem != nullptr) delete _Elem;
}

Vector1::Vector1(Vector1 & vec)
{
	_Elem = (int*)malloc(100 * sizeof(int));
	dimension = vec.dimension;
	for (int i = 0; i < dimension; i++) {
		_Elem[i] = vec._Elem[i];
	}
}

string Vector1::getVecInStr(){
    string result = "";
    for(int i = 0;i<dimension;i++)
    {
    
        result = result + to_string(this->_Elem[i]) + " ";
    }
    return result;
}

#include "pch.h"
#include <iostream>

using namespace std;

int borderFunc(int num) {
	int high = 100;
	int low = -10;

	if (num < low)
	{
		return low;
	}
	if (num > high)
	{
		return high;
	}

	return num;
}

double borderFunc(double num) {
	double high = 100.2;
	double low = -10.3;

	if (num < low)
	{
		return low;
	}
	if (num > high)
	{
		return high;
	}

	return num;
}

int main()
{
	int numInt;
	double numDouble;
	cout << "Unesite vrijednost broja u int i double: "<< endl;
	cin >> numInt >> numDouble;

	cout << "Vrijednost int: " << borderFunc(numInt) << endl;
	cout << "Vrijednost double: " << borderFunc(numDouble);
}


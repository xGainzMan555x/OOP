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
	cout << "Vrijednost int: " << borderFunc(52) << endl;
	cout << "Vrijednost double: " << borderFunc(13.2);

	cout << "Vrijednost int: " << borderFunc(-15) << endl;
	cout << "Vrijednost double: " << borderFunc(-10.5);
	
	cout << "Vrijednost int: " << borderFunc(110) << endl;
	cout << "Vrijednost double: " << borderFunc(100.3);
}


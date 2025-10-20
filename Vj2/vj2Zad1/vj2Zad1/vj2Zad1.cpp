#include "pch.h"
#include <iostream>

using namespace std;

int* fibonacci(int n) {
	int* arrFib = (int*)malloc(sizeof(int) * n);

	arrFib[0] = 1;
	arrFib[1] = 1;

	for (int i = 2; i < n; i++)
	{
		arrFib[i] = arrFib[i - 1] + arrFib[i - 2];
	}

	return arrFib;
}

int main()
{
	int n = 10;

	int* arrFib = fibonacci(n);

	for (int i = 0; i < n; i++)
	{
		cout << arrFib[i] << " ";
	}

	delete(arrFib);

	return 0;
}


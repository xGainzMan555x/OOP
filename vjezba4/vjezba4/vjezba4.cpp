#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

void input_vector(vector<int>& v) {
	int inputValue = 1;

	while (true)
	{
		cin >> inputValue;
		if (inputValue != 0)
		{
			v.push_back(inputValue);
		}
		else
		{
			break;
		}
	}
}

void print_vector(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++)
	{
		cout << i << ". element: " << v.at(i) << endl;
	}
}

int main()
{
		     
}


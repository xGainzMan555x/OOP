#include <iostream>

using namespace std;

int& at(int* arr, int i) {
    return arr[i];
}

int main()
{
    int arr[] = { 3, 34, 4535, 30, 10 };
    int i = 3;

    cout << "Niz prije: " << arr[i] << endl;

    at(arr, i) = at(arr, i) + 1;

    cout << "Niz poslije: " << arr[i] << endl;

    return 0;
}

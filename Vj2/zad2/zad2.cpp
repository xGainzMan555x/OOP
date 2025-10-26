#include <iostream>

using namespace std;

struct Vector{
    int* arr;
    int size;
    int cap;
};

Vector vector_new(int init_capacity){
    Vector v;

    v.arr = new int[init_capacity];
    v.size = 0;
    v.cap = init_capacity;

    return v;
}

void vector_delete(Vector& v){
    delete[] v.arr;
    v.arr = nullptr;
}

void vector_push_back(Vector& v, int element){
    if(v.size == v.cap)
    {
        int newCap = v.cap * 2;

        int* newArr = new int[newCap];

        for(int i = 0; i < v.size; i++)
        {
            newArr[i] = v.arr[i];
        }

        delete[] v.arr;
        v.arr = newArr;
        v.cap = newCap;
    }

    v.arr[v.size] = element;
    v.size++;
}

void vector_pop_back(Vector& v){
    if(v.size > 0)
    {
        v.size--;
    }
}

int vector_front(Vector& v){
    return v.arr[0];
}

int vector_back(Vector& v){
    return v.arr[v.size - 1];
}

int vector_size(Vector& v){
    return v.size;
}

int main()
{
    Vector v = vector_new(2);  
    
    vector_push_back(v, 10);   
    vector_push_back(v, 20);
    vector_push_back(v, 30);
    
    cout << "Front: " << vector_front(v) << endl;
    cout << "Back: " << vector_back(v) << endl;
    cout << "Size: " << vector_size(v) << endl;
    
    vector_delete(v);

    return 0;
}
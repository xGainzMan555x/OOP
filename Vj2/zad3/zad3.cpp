#include <iostream>
#include <iomanip>

using namespace std;

struct Matrix
{
    double** value;
    int row;
    int col;
};

Matrix newMatrix(int m, int n){
    Matrix mat;

    mat.value = new double*[m];
    mat.row = m;
    mat.col = n;

    for(int i = 0; i < m; i++)
    {
        mat.value[i] = new double[n];
    }

    return mat;
}

void inputMatrix(Matrix mat){
    cout << "Unesite elemente matrice " << mat.row << "x" << mat.col << ":" << endl;

    for (int i = 0; i < mat.row; i++) {
        for (int j = 0; j < mat.col; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> mat.value[i][j];
        }
    }
}

void genMatrix(Matrix mat){
    double min;
    double max;

    cout << "Unesite raspon vrijednosti: " << endl;
    cin >> min >> max;

    for(int i = 0; i < mat.row; i++)
    {
        for(int j = 0; j < mat.col; j++)
        {
            mat.value[i][j] = min + (double)rand() / RAND_MAX * (max -min);
        }
    }
}

Matrix matrixAdd(Matrix A, Matrix B){
    if (A.row != B.row || A.col != B.col) {
        cout << "Greška: Matrice moraju biti istih dimenzija!" << endl;
        return A;
    }

    Matrix rez = newMatrix(A.row, A.col);

    for(int i = 0; i < A.row; i++)
    {
        for(int j = 0; j < A.col; j++)
        {
            rez.value[i][j] = A.value[i][j] + B.value[i][j];
        }
    }

    return rez;
}

Matrix matrixSub(Matrix A, Matrix B){
    if (A.row != B.row || A.col != B.col) {
        cout << "Greška: Matrice moraju biti istih dimenzija!" << endl;
        return A;
    }

    Matrix rez = newMatrix(A.row, A.col);

    for(int i = 0; i < A.row; i++)
    {
        for(int j = 0; j < A.col; j++)
        {
            rez.value[i][j] = A.value[i][j] - B.value[i][j];
        }
    }

    return rez;
}

Matrix matrixMulltiply(Matrix A, Matrix B){
    if (A.col != B.row) {
        cout << "Greška: Matrice nisu kompatibilne!" << endl;
        return A;
    }

    Matrix rez = newMatrix(A.row, B.col);

    for (int i = 0; i < A.row; i++) {
        for (int j = 0; j < B.col; j++) {
            rez.value[i][j] = 0;
            for (int k = 0; k < A.col; k++) {
                rez.value[i][j] += A.value[i][k] * B.value[k][j];
            }
        }
    }

    return rez;
}

Matrix matrixTranspose(Matrix mat){
    Matrix rez = newMatrix(mat.col, mat.row);

    for(int i = 0; i < mat.row; i++)
    {
        for(int j = 0; j < mat.col; j++)
        {
            rez.value[j][i] = mat.value[i][j];
        }
    }

    return rez;
}

void printMatrix(Matrix mat){
    for(int i = 0; i < mat.row; i++)
    {
        for(int j = 0; j < mat.col; j++)
        {
            cout << setw(10) << right << fixed 
                      << setprecision(4) << mat.value[i][j] << " ";
        }
    }
}

void delMatrix(Matrix mat){
    for (int i = 0; i < mat.row; i++) {
        delete[] mat.value[i];
    }
    delete[] mat.value;
}

int main()
{
    srand(time(0));

    Matrix A = newMatrix(3, 3);
    genMatrix(A);

    Matrix B = newMatrix(3, 3);
    genMatrix(B);

    Matrix sum = matrixAdd(A, B);
    
    printMatrix(sum);
    delMatrix(sum);

    Matrix sub = matrixSub(A, B);
    
    printMatrix(sub);
    delMatrix(sub);

    Matrix add = matrixAdd(A, B);
    
    printMatrix(add);
    delMatrix(add);

    Matrix mul = matrixMulltiply(A, B);
    
    printMatrix(mul);
    delMatrix(mul);

    Matrix AT = matrixTranspose(AT);
    
    printMatrix(AT);
    delMatrix(AT);

    return 0;
}
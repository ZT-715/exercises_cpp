/*
 Tarefa D:
Prepare uma classe que represente uma matriz QUADRADA de valores reais, podendo ir até a dimensão 3x3 (de forma a evitar ter que realizar alocação dinâmica de memória). A classe deve ter um construtor solicitando a dimensão, da matriz, minimamente.
Além disso, a classe deve apresentar os seguintes métodos:
1) métodos que permitam setar e recuperar cada uma das posições válidas da matriz, de acordo com a dimensão da sua criação
2) método que permita realizar a soma de duas matrizes (a matriz do objeto com outra matriz informada)
3) método que permita realizar a subtração de duas matrizes (a matriz do objeto com outra matriz informada)
4) método que permita determinar o determinante da matriz
Uma função main() que permita exemplificar a operação da classe.
*/

#include<iostream>
#include<stdexcept>
using namespace std;

class Matrix {
    float matriz[3][3];
    int n;
public:
    Matrix(int i);
    int size();
    float get(int, int);
    int print();
    int sum(Matrix);
    int sub(Matrix);
    float det();
};

Matrix::Matrix(int i) {
    if (i > 3 || i <= 1) {
        throw invalid_argument("Matrix is 3x3 maximum.");
    }
    n = i;

    for (int j = 0; j < n; j++) {
        for (int m = 0; m < n; m++) {
            matriz[m][j] = m+j+1.0;
        }
    }
}

int Matrix::size() {
    return n;
}

float Matrix::get(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= n) {
        throw invalid_argument("Index outside range.");
    }
    return matriz[i][j];
}

int Matrix::print() {
    for (int i = 0; i < n; i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            cout << get(i, j);
            if (j >= 0 && j < n-1 ) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}

int Matrix::sum(Matrix b) {
    if (n != b.size()) {
        throw invalid_argument("Matrices of different dimensions.");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] += b.get(i, j);
        }
    }
    return 0;
}

int Matrix::sub(Matrix b) {
    if (n != b.size()) {
        throw invalid_argument("Matrices of different dimensions.");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] -= b.get(i, j);
        }
    }
    return 0;
}

float Matrix::det() {
    int pivot;
    float multiplier {0.0};
    float f[3][3];
    float det {1.0};

    // Convert matrix to float
    for (int i {0}; i < n; i++) {
        for (int j {0}; j < n; j++) {
            f[i][j] = matriz[i][j];
        }
    }
    // Factorize matrix U
    for (int pivot_line {0}; pivot_line < n; pivot_line++) {
        // Diagonal values
        pivot = f[pivot_line][pivot_line];

        if (pivot == 0.0) return 0.0;

        // For each line below the current one, subtract the pivot line times the
        // multiplier necessary to zero out the values below the pivot,
        // thus forming the U matrix of the LU factorization.
        for (int nx_line = pivot_line + 1; nx_line < n; nx_line++) {
            multiplier = f[nx_line][pivot_line] / pivot;
            for (int coluna {pivot_line}; coluna < n; coluna++) {
                f[nx_line][coluna] -= f[pivot_line][coluna] * multiplier;
            }
        }
    }
    // Det(U) is the product of the diagonal
    for (int i {0}; i < n; i++) {
        det *= f[i][i];
    }
    return det;
}

int main(void) {
    int n;
    cout << "Dimensions of the matrix (2 to 3): ";
    cin >> n;

    Matrix a(n);
    cout << endl << "1st matrice: " << endl;
    a.print();

    Matrix b(n);
    cout << endl << "2st matrice: " << endl;
    b.print();
 
    cout << endl << "Element at position (0,0) of the 1st matrix: " << a.get(0, 0) << endl;
    cout << endl << "Element at position (0,0) of the 2nd matrix: " << b.get(0, 0) << endl << endl;

    cout << endl << "Determinant of the 1st matrix: " << a.det() << endl;
    cout << endl << "Determinant of the 2nd matrix: " << b.det() << endl << endl;
   
    cout << endl << "Sum of the 1st matrix with the 2nd: " << endl;
    cout << endl << "1st matrice: " << endl;
    a.print();
    cout << endl << "2st matrice: " << endl;
    b.print();
    cout << endl << "Result: " << endl;
    a.sum(b);
    a.print();

    cout << endl << "Subtraction of the 1st matrix on the 2nd: " << endl;
    cout << endl << "1st matrice: " << endl;
    b.print();
    cout << endl << "2st matrice: " << endl;
    a.print();
    cout << endl << "Result: " << endl;
    b.sub(a);
    b.print();

    return 0;
}

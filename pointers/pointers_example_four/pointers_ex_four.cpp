#include <iostream>

// Function prototypes
int** create2DArray(int rows, int cols);
void inputArray(int** arr, int rows, int cols);
void displayArray(int** arr, int rows, int cols);
void delete2DArray(int** arr, int rows);

int main() {
    int rows, cols;
    
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    int** matrix = create2DArray(rows, cols);

    if (!matrix) {
        std::cout << "Memory allocation failed!";
        return 1;
    }

    inputArray(matrix, rows, cols);
    displayArray(matrix, rows, cols);

    delete2DArray(matrix, rows);

    return 0;
}

int** create2DArray(int rows, int cols) {
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    return arr;
}

void inputArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            std::cin >> arr[i][j];
        }
    }
}

void displayArray(int** arr, int rows, int cols) {
    std::cout << "Matrix elements are: " << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void delete2DArray(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

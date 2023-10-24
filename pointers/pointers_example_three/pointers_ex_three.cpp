#include <iostream>

int main() {
    int size;
    
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    
    // Dynamically allocate memory for an array using 'new'
    int* arr = new int[size];

    // Check if memory allocation was successful
    if (!arr) {
        std::cout << "Memory allocation failed!";
        return 1;
    }

    // Input array values using pointer arithmetic
    for (int i = 0; i < size; i++) {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> *(arr + i);  // Equivalent to arr[i]
    }

    // Display array values using pointer arithmetic
    std::cout << "Entered elements are: ";
    for (int i = 0; i < size; i++) {
        std::cout << *(arr + i) << " ";  // Equivalent to arr[i]
    }
    std::cout << std::endl;

    // Deallocate memory
    delete[] arr;

    return 0;
}

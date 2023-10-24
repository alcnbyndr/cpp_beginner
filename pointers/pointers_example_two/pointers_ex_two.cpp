#include <iostream>

// Function prototype
void doubleValue(int* p);

int main() {
    int number = 5;
    std::cout << "Original number: " << number << std::endl;

    doubleValue(&number);   // Pass the address of 'number' to the function

    std::cout << "Number after doubling: " << number << std::endl;

    return 0;
}

// Function definition
void doubleValue(int* p) {
    *p = *p * 2;  // Dereference the pointer and double the value it points to
}

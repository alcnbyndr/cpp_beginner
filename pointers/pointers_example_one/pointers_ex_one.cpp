#include <iostream>

int main() {
    int num = 10;             // Declare an integer variable
    int* pointerToNum;        // Declare a pointer to an integer

    pointerToNum = &num;      // Assign the address of 'num' to 'pointerToNum'

    std::cout << "Value of num: " << num << std::endl;                       // Print the value of 'num'
    std::cout << "Address of num: " << &num << std::endl;                    // Print the address of 'num'
    
    std::cout << "Value stored in pointerToNum: " << pointerToNum << std::endl;    // Print the value (address) stored in 'pointerToNum'
    std::cout << "Value pointed by pointerToNum: " << *pointerToNum << std::endl;  // Dereference 'pointerToNum' to get the value of 'num'

    return 0;
}

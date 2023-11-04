// Precious Maku oem354
// Exercise 6

#include <iostream>
#include <vector>


void splitOddEven(const std::vector<int>& input, std::vector<int>& odd, std::vector<int>& even) {
    for (int num : input) {
        if (num % 2 == 0) {
            // If the number is even, add it to the 'even' vector
            even.push_back(num);
        }
        else {
            // If the number is odd, add it to the 'odd' vector
            odd.push_back(num);
        }
    }
}

int main() {
    // Input 
    std::vector<int> input = { 5, 6, 2, 4, 5 };

    std::vector<int> oddNumbers;
    std::vector<int> evenNumbers;

    splitOddEven(input, oddNumbers, evenNumbers);

    // show odd and even vectors
    std::cout << "Odd Numbers: ";
    for (int num : oddNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Even Numbers: ";
    for (int num : evenNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

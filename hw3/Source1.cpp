#include <iostream>
#include <vector>

// Function to calculate the Collatz sequence length for a given starting value
int collatzSequenceLength(long long startingValue) {
    int length = 1;
    while (startingValue != 1) {
        if (startingValue % 2 == 0) {
            startingValue /= 2;
        }
        else {
            startingValue = 3 * startingValue + 1;
        }
        length++;
    }
    return length;
}

int main() {
    long long maxStartValue = 1;
    int maxLength = 1;

    for (long long startingValue = 1; startingValue <= 1000; startingValue++) {
        int length = collatzSequenceLength(startingValue);

        if (length > maxLength) {
            maxLength = length;
            maxStartValue = startingValue;
            std::cout << "New maximum sequence length found with starting value " << maxStartValue << ": " << maxLength << " steps." << std::endl;
        }
    }

    std::cout << "The starting value that leads to the longest sequence is " << maxStartValue << " with a length of " << maxLength << " steps." << std::endl;

    return 0;
}

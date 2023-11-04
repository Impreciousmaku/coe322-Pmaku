//Precious Maku oem354

#include <iostream>
using namespace std;

// Function that calculate the Collatz sequence length for a given starting number
int collatzSequenceLength(long long n) {
    int length = 1;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        }
        else {
            n = 3 * n + 1;
        }
        length++;
    }
    return length;
}

int main() {
    int max_length = 0;
    int max_starting_number = 0;

    // Repeat through starting values u1 from 1 to 1000
    for (int u1 = 1; u1 <= 1000; u1++) {
        int length = collatzSequenceLength(u1);
        if (length > max_length) {
            max_length = length;
            max_starting_number = u1;
            cout << "New maximum sequence length found! Starting number: " << max_starting_number << " Length: " << max_length << endl;
        }
    }
    // What happens if you keep iterating after reaching 1?
    cout << "The starting number that leads to the longest Collatz sequence is: " << max_starting_number << endl;
    cout << "The sequence length is: " << max_length << endl;

    return 0;
}
//If you keep iterating the Collatz sequence after reaching 1,the sequence will continue in a loop. 

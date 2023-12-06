// TACC Username: olusemiloremaku3773
//Precious Maku oem354
// Excercise 4
#include <iostream>
#include <cmath>

class primegenerator {
private:
    int count; // To keep track of the number of primes found
    int current; // To store the current number being checked for primality

    // Function to check if a number is prime
    bool isprime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

public:
    // Constructor initializes count and current
    primegenerator() : count(0), current(1) {}

    // Method to return the number of primes found so far
    int number_of_primes_found() const {
        return count;
    }

    // Method to find the next prime number
    int nextprime() {
        while (true) {
            ++current;
            if (isprime(current)) {
                ++count;
                return current;
            }
        }
    }
};

int main() {
    int nprimes;
    std::cout << "Enter the number of primes to find: ";
    std::cin >> nprimes;

    primegenerator sequence;

    while (sequence.number_of_primes_found() < nprimes) {
        int number = sequence.nextprime();
        std::cout << "Number " << number << " is prime" << '\n';
    }

    return 0;
}

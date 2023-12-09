// TACC Username: olusemiloremaku3773
//Precious Maku oem354
// Excercise 6

#include <iostream>
#include <vector>
#include <numeric>
#include <ranges>

bool is_perfect(int number) {
    int sum = std::accumulate(std::ranges::views::iota(1, number) | std::ranges::views::filter([number](int div) { return number % div == 0; }), 0);
    return sum == number;
}

int main() {
    int count = 0;
    int current_number = 1;

    while (count < 4) {
        if (is_perfect(current_number)) {
            std::cout << current_number << " is a perfect number." << std::endl;
            ++count;
        }
        ++current_number;
    }

    return 0;
}
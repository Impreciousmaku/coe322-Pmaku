// TACC Username: olusemiloremaku3773
//Precious Maku oem354
// Excercise 7


#include <iostream>
#include <fmt/format.h>  // Include fmtlib header

int main() {
    // Print a message using fmtlib
    fmt::print(" C++ with fmtlib!\n");

    // Display hexadecimal output with proper alignment
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 16; ++j) {
            // Using fmtlib to format hexadecimal values
            fmt::print("{:02X} ", i * 16 + j);
        }
        fmt::print("\n");
    }

    return 0;
}


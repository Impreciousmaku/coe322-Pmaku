// TACC Username: olusemiloremaku3773
//Precious Maku oem354
// Excercise 6

#include <iostream>
#include <cmath>
#include <functional>
#include <cxxopts.hpp>

// Newton root finding function with exact derivative
double newton_root(std::function<double(double)> f, std::function<double(double)> df, double initial_guess, int max_iterations = 100, double tolerance = 1e-9) {
    double x = initial_guess;

    for (int i = 0; i < max_iterations; ++i) {
        double fx = f(x);
        double dfx = df(x);

        if (std::abs(fx) < tolerance) {
            return x;
        }

        x = x - fx / dfx;
    }

    return x;
}
// Newton root finding function with finite difference approximation for derivative
double newton_root(std::function<double(double)> f, double initial_guess, int max_iterations = 100, double tolerance = 1e-9) {
    const double h = 1e-6;
    auto df = [f, h](double x) {
        return (f(x + h) - f(x)) / h;
    };

    return newton_root(f, df, initial_guess, max_iterations, tolerance);
}

int main(int argc, char* argv[]) {
    cxxopts::Options options("Newton Program", "Newton root finding program");
    options.add_options()
        ("v,value", "Initial guess value", cxxopts::value<double>());

    auto result = options.parse(argc, argv);

    if (!result.count("value")) {
        std::cerr << "Error: Missing required argument -v/--value\n";
        return 1;
    }

    double initial_guess = result["value"].as<double>();

    // Exercise 4: Compute roots in a loop
    for (int n = 2; n <= 8; ++n) {
        auto f = [n](double x) { return x * x - n; };
        double root = newton_root(f, initial_guess);
        std::cout << "sqrt(" << n << ") = " << root << '\n';
    }

    // Exercise 5: Root finding function with finite difference approximation
    auto f = [](double x) { return x * x - 3.14; };
    double root_with_fd = newton_root(f, initial_guess);
    std::cout << "sqrt(3.14) using finite difference: " << root_with_fd << '\n';

    return 0;
}

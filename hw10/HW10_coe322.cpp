// TACC Username: olusemiloremaku3773
//Precious Maku oem354
// Excercise 10

//1. Function with positive output : C++

double f(int n) {
    if (n < 0) {
        // Handle negative input
        return -f(-n); // Flip sign
    }
    else if (n == 0) {
        // Special case for zero
        return 1.0; // Any positive value
    }
    else {
        // Positive input
        return n * f(n - 1); // Recursive call
    }
}
//2. Unit Test : C++



TEST(fFunctionTest, PositiveOutput) {
    EXPECT_EQ(f(0), 1.0); // Special case
    EXPECT_GT(f(1), 0.0); // Positive output
    EXPECT_GT(f(2), 0.0);
    EXPECT_GT(f(3), 0.0);
    EXPECT_GT(f(10), 0.0);
}
//3. Constructor with exception : C++

class Polynomial {
public:
    Polynomial(const vector<double>& coefficients) {
        if (coefficients.empty()) {
            throw std::invalid_argument("Empty coefficient list");
        }
        if (coefficients[0] == 0.0) {
            throw std::invalid_argument("Zero-th coefficient must be non-zero");
        }
        // Store coefficients
        this->coefficients = coefficients;
    }
private:
    vector<double> coefficients;
};

//4. is_odd Function Implementation : C++

bool is_odd(const Polynomial & p) {
    return p.get_degree() % 2 == 1;
}

//5. Unit Test for is_odd(Assuming you have a get_degree() function) :C++


TEST(is_oddTest, OddAndEvenDegree) {
    // Second degree polynomial (even)
    Polynomial second(2, 0, 1); // 2x^2 + 1
    EXPECT_FALSE(is_odd(second));

    // Third degree polynomial (odd)
    Polynomial third(3, 2, 0, 1); // 3x^3 + 2x^2 + 1
    EXPECT_TRUE(is_odd(third));
}
//6. Overloaded Polynomial Evaluation : C++

double Polynomial::operator()(double x) const {
    double result = 0.0;
    for (int i = coefficients.size() - 1; i >= 0; --i) {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

//7. Unit Test for Overloaded Evaluation : C++



TEST(PolynomialEvaluationTest, CorrectEvaluation) {
    // Second degree polynomial
    Polynomial second(vector<double>{2, 0, 1.1}); // 2x^2 + 1.1

    // Correct interpretation: 2x^2 + 1.1
    EXPECT_NEAR(second(2), 9.1, 0.001);

    // Third degree polynomial
    Polynomial third(vector<double>{3, 2, 0, 1}); // 3x^3 + 2x^2 + 1

    EXPECT_NEAR(third(0), 1, 0.001);
}


TEST(InitialBoundsTest, LeftRightValues) {
    // Define polynomial and initial bounds
    Polynomial third({ 3, 2, 0, 1 }); // 3x^3 + 2x^2 + 1
    double left = 10.0;
    double right = 11.0;

    // Ensure left and right are in correct order
    EXPECT_LT(left, right);

    // Calculate function values at left and right bounds
    double left_value = third(left);
    double right_value = third(right);

    // Verify product of left and right values is negative or zero
    EXPECT_LE(left_value * right_value, 0.0);
}


//1. move_bounds_closer :


    TEST(MoveBoundsCloserTest, Exceptions) {
    // Define polynomial and bounds
    Polynomial third({ 3, 2, 0, 1 }); // 3x^3 + 2x^2 + 1
    double left = 10.0;
    double right = 11.0;

    // Expect exceptions for invalid cases
    EXPECT_THROWS(move_bounds_closer(third, right, left));
    EXPECT_THROWS(move_bounds_closer(third, left, left));
}

TEST(MoveBoundsCloserTest, CorrectBoundsUpdate) {
    // Define polynomial and bounds
    Polynomial third({ 3, 2, 0, 1 }); // 3x^3 + 2x^2 + 1
    double left = 10.0;
    double right = 11.0;
    double old_left = left, old_right = right;

    // Expect no exception and verify updated bounds
    EXPECT_NO_THROW(move_bounds_closer(third, left, right));
    EXPECT_LE(left * right, 0.0);
    EXPECT(((left == old_left && right < old_right) || (right == old_right && left > old_left)));
}
// 2. find_zero:


TEST(FindZeroTest, RootFindingPrecision) {
    // Define polynomial and expected root
    Polynomial third({ 3, 2, 0, 1 }); // 3x^3 + 2x^2 + 1
    double expected_root = 1.0;

    // Find the root
    double found_root = find_zero(third.get_coefficients(), 1e-8);

    // Verify root accuracy within specified precision
    EXPECT_NEAR(found_root, expected_root, 1e-8);
}

//1.Test move_bounds_closer :

TEST(MoveBoundsCloserTest, ThrowsOnInvalidInput) {
    // Polynomial with even degree
    Polynomial second({ 2, 0, 1 }); // 2x^2 + 1

    // Cannot move bounds closer for even degree polynomial
    EXPECT_THROW(move_bounds_closer(second, 10.0, 11.0), std::runtime_error);

    // Moving bounds with same value throws exception
    Polynomial third({ 3, 2, 0, 1 }); // 3x^3 + 2x^2 + 1
    EXPECT_THROW(move_bounds_closer(third, 10.0, 10.0), std::runtime_error);
}

TEST(MoveBoundsCloserTest, UpdatesBoundsCorrectly) {
    // Polynomial with odd degree
    Polynomial third({ 3, 2, 0, 1 }); // 3x^3 + 2x^2 + 1

    // Initial bounds
    double left = 10.0;
    double right = 11.0;

    // Store old bounds
    double old_left = left;
    double old_right = right;

    // Move bounds closer
    EXPECT_NO_THROW(move_bounds_closer(third, left, right));

    // Verify bounds are updated
    EXPECT_TRUE(left_value * right_value <= 0.0);
    EXPECT_TRUE((left == old_left && right < old_right) || (right == old_right && left > old_left));
}
2. Test find_zero :


TEST(FindZeroTest, FindsRootWithCorrectPrecision) {
    // Polynomial with a known root
    Polynomial third({ 3, 2, 0, -1 }); // 3x^3 + 2x^2 - 1

    // Expected root and tolerance
    double expected_root = 0.5;
    double tolerance = 1e-8;

    // Find the root
    double actual_root = find_zero(third, tolerance);

    // Verify root is found with expected precision
    EXPECT_NEAR(actual_root, expected_root, tolerance);
}

TEST(FindZeroTest, HandlesEvenDegreePolynomials) {
    // Polynomial with even degree
    Polynomial second({ 2, 0, 1 }); // 2x^2 + 1

    // Expect exception for even degree polynomials
    EXPECT_THROW(find_zero(second, 1e-8), std::runtime_error);
}


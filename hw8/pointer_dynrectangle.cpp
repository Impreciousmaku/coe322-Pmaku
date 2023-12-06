// TACC Username: olusemiloremaku3773
//Precious Maku oem354
// Excercise 8

// pointer_dynrectangle.cpp

#include <iostream>
#include <memory>

class Point {
public:
    float x, y;

    Point(float x, float y) : x(x), y(y) {}

    float dx(Point other) {
        return other.x - x;
    }
};

int main() {
    // main, with objects
    Point oneone(1, 1), fivetwo(5, 2);
    float dx1 = oneone.dx(fivetwo);
    std::cout << "dx: " << dx1 << std::endl;

    // main, with pointers
    auto oneonep = std::make_shared<Point>(1, 1);
    auto fivetwop = std::make_shared<Point>(5, 2);
    float dx2 = oneonep->dx(*fivetwop);
    std::cout << "dx: " << dx2 << std::endl;

    return 0;
}

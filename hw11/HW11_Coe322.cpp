// TACC Username: olusemiloremaku3773
//Precious Maku oem354
// Excercise 11
// namedvector.h (header file)

//Exercise 4
#include <string>
#include <vector>

template <typename T>
class namedvector {
public:
    namedvector(const std::string& name, size_t size) : name_(name), data_(size) {}

    const std::string& name() const {
        return name_;
    }

    size_t size() const {
        return data_.size();
    }

    const T& at(size_t index) const {
        return data_.at(index);
    }

    T& at(size_t index) {
        return data_.at(index);
    }

private:
    std::string name_;
    std::vector<T> data_;
};

// object/container.cpp
#include "namedvector.h"
#include <iostream>

int main() {
    namedvector<float> fivetemp("five", 5);
    std::cout << fivetemp.name() << ": " << fivetemp.size() << '\n';
    std::cout << "at zero: " << fivetemp.at(0) << '\n';

    return 0;
}


// Excerise 5 
// geo_vector.h (header file)
#pragma once

#include <string>
#include <vector>

namespace geo {
    template <typename T>
    class vector {
    public:
        vector(const std::string& name, size_t size) : name_(name), data_(size) {}

        const std::string& name() const {
            return name_;
        }

        size_t size() const {
            return data_.size();
        }

        const T& at(size_t index) const {
            return data_.at(index);
        }

        T& at(size_t index) {
            return data_.at(index);
        }

        // Overload the subscript operator for easy access
        T& operator[](size_t index) {
            return data_[index];
        }

        const T& operator[](size_t index) const {
            return data_[index];
        }

    private:
        std::string name_;
        std::vector<T> data_;
    };
} 

// object/container.cpp
#include "geo_vector.h"
#include <iostream>

int main() {
    using namespace geo;

    vector<float> float4("four", 4);
    std::cout << float4.name() << '\n';
    float4[1] = 3.14;
    std::cout << float4.at(1) << '\n';

    vector<std::string> string3("three", 3);
    string3.at(2) = "abc";
    std::cout << string3[2] << '\n';

    return 0;
}


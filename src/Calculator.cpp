#include "Calculator.hpp"
#include <stdexcept>

int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::subtract(int a, int b) {
    return a - b;
}

int Calculator::divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Cannot divide by 0");
    } 

    return a / b;
    
}

int Calculator::multiply(int a, int b) {
    return a * b;
}
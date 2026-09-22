#include <iostream>
#include "Calculator.hpp"

int main () {
    Calculator calculator;

    std::cout << calculator.add(25,5) << std::endl;
    std::cout << calculator.subtract(25,5) << std::endl;
    std::cout << calculator.divide(25,5) << std::endl;
    std::cout << calculator.multiply(25,5) << std::endl;
    std::cout << calculator.divide(0,25) << std::endl;
    std::cout << calculator.divide(25,0) << std:: endl;
}
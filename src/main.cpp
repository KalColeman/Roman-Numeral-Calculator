#include <iostream>
#include "Calculator.hpp"
#include "Converter.hpp"

int main () {
    Calculator calculator;
    Converter converter;

    std::cout << calculator.add(25,5) << std::endl;
    std::cout << calculator.subtract(25,5) << std::endl;
    std::cout << calculator.divide(25,5) << std::endl;
    std::cout << calculator.multiply(25,5) << std::endl;
    std::cout << calculator.square(4) << std::endl;
    std::cout << calculator.divide(0,25) << std::endl;
    std::cout << converter.romanToInt("III") << std::endl;
    std::cout << converter.romanToInt("IV") << std::endl;
    std::cout << converter.romanToInt("VI") << std::endl;
    std::cout << converter.romanToInt("MCMXCIV") << std::endl;
    std::cout << converter.romanToInt("MCMXCA") << std::endl;
}
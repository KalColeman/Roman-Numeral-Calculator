#include <iostream>
#include "Calculator.hpp"
#include "Converter.hpp"
#include "Validation.hpp"

int main () {
    Calculator calculator;
    Converter converter;
    Validator validation;

    std::cout << converter.romanToInt("MCMXCIV") << std::endl;
    std::cout << converter.romanToInt("III") << std::endl;
    std::cout << converter.intToRoman(1) << std::endl;
    std::cout << converter.intToRoman(3999) << std::endl;
    std::cout << converter.intToRoman(4000) << std::endl;
}
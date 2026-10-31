#include <iostream>
#include "Calculator.hpp"
#include "Converter.hpp"
#include "Validation.hpp"

int main () {
    Calculator calculator;
    Converter converter;
    Validator validation;

    std::cout << validation.valid("MCMXCIV") << std::endl;
    std::cout << validation.valid("XCIX") << std::endl;
    std::cout << validation.valid("XLI") << std::endl;
    std::cout << validation.valid("IIX") << std::endl;
    std::cout << validation.valid("IXX") << std::endl;
    std::cout << validation.valid("XXC") << std::endl;
    std::cout << validation.valid("IL") << std::endl;
    std::cout << validation.valid("VX") << std::endl;
    std::cout << validation.valid("VV") << std::endl;
    std::cout << validation.valid("IIII") << std::endl;
}
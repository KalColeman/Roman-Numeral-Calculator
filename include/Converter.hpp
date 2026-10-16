#ifndef CONVERTER_HPP
#define CONVERTER_HPP
#include <string>

class Converter {
public:
    int romanToInt(const std::string& roman);
    std::string intToRoman(int number);
};

#endif
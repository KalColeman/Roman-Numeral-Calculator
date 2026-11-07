#include "Converter.hpp"
#include "Validation.hpp"
#include <stdexcept>
#include <unordered_map>
#include <cstddef>
#include <vector>
#include <utility>

int Converter::romanToInt(const std::string& roman) {
    Validator validator;
    if (!validator.valid(roman)) {
        throw std::invalid_argument("Please try again! The input was not a valid Roman Numeral!");
    }
    static const std::unordered_map<char,int> romanInts = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };

    std::size_t romanSize = roman.size();

    int result = 0;
    for (std::size_t i = 0; i < romanSize; i++) {
        auto it = romanInts.find(roman[i]);

        if (it != romanInts.end()) {
            if (i + 1 < romanSize) {
                auto nextInt = romanInts.find(roman[i+1]);
                if (nextInt->second > it->second) {
                    result += nextInt->second - it->second;
                    i++;
                } else {
                    result += it->second;
                }
            } else {
                result += it->second;
            }
        } 
    }
    return result;
}
std::string Converter::intToRoman(int x) {
    std::string romanNumeral = "";
    if (x == 0) {
        throw std::invalid_argument("Please try again! 0 can not be represented in Roman numerals!");
    }
    if (x < 0) {
        throw std::invalid_argument("Please try again! Negative numbers can not be represented with Roman Numerals!");
    }
    if (x > 3999) {
        throw std::invalid_argument("Please try again! The max value this program currently supports is 3,999. Sorry for the inconvenience!");
    }
    static const std::vector<std::pair<int, std::string>> romanInts = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
    for (const auto& roman : romanInts) {
        while (x >= roman.first) {
            romanNumeral = romanNumeral + roman.second;
            x -= roman.first;
        }
    }
    return romanNumeral;
}
#include "Converter.hpp"
#include <stdexcept>
#include <unordered_map>
#include <cstddef>

int Converter::romanToInt(const std::string& roman) {
    static const std::unordered_map<char,int> romanInts = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };

    if (roman.empty()) {
        throw std::invalid_argument("Please try again! The input was empty!");
    }
    std::size_t romanSize = roman.size();

    int result = 0;
    for (std::size_t i = 0; i < romanSize; i++) {
        auto it = romanInts.find(roman[i]);

        if (it != romanInts.end()) {
            if (i + 1 < romanSize) {
                auto nextInt = romanInts.find(roman[i+1]);
                if (nextInt != romanInts.end()) {
                    if (nextInt->second > it->second) {
                        result += nextInt->second - it->second;
                        i++;
                    } else {
                        result += it->second;
                    }
                } else {
                    throw std::invalid_argument(std::string(1,roman[i+1]) + " isn't a valid Roman numeral.");
                }
            } else {
                    result += it->second;
            }
        } else {
            throw std::invalid_argument(std::string(1,roman[i]) +  " isn't a valid Roman numeral.");
        } 
    }
    return result;
}
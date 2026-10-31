#include "Validation.hpp"
#include <stdexcept>
#include <unordered_map>

bool Validator::validRomanNum(std::string romanNum) {
    if (romanNum.empty()) return false;
    int i = romanNum.size() - 1;

    
    int currVal = 0;
    int leftVal = 0;
    int groupVal = 0;
    int previousGroupVal = 0;
    

    static const std::unordered_map<char,int> romanInts = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };
    

    for (char c : romanNum) {
        auto it = romanInts.find(c);
        if (it != romanInts.end()) {
            continue;
        } else {
            return false;
        }
    }
    if (romanNum.size() == 1) {
        return true;
    }
    
    while (i >= 0) {
        if (i == 0) {
            groupVal = romanInts.find(romanNum[i])->second;
            if (groupVal < previousGroupVal) {
                return false;
            } else {
                return true;
            }
        }
        auto currChar = romanInts.find(romanNum[i]);
        auto leftChar = romanInts.find(romanNum[i-1]);
        
        currVal = currChar->second;
        leftVal = leftChar->second;

        if (leftVal < currVal) {
            if (previousGroupVal >= leftVal) {
                return false;
            }
            if (currVal == 5 || currVal == 10) {
                if (leftVal != 1) {
                    return false;
                }
                groupVal = currVal - leftVal;
            } else if (currVal == 50 || currVal == 100) {
                if (leftVal != 10) {
                    return false;
                }
                groupVal = currVal - leftVal;
            } else if (currVal == 500 || currVal == 1000) {
                if (leftVal != 100) {
                    return false;
                }
                groupVal = currVal - leftVal;
            } else {
                return false;
            }
            i = i-2;
        } else {
            groupVal = currVal;
            i--;
        }
        if (groupVal < previousGroupVal) {
            return false;
        }
        previousGroupVal = groupVal;

    }
    return true;
}
bool Validator::validRepitition(std::string romanNum) {
    int i = 0;
    int count = 1;
    while (i < romanNum.size()) {
        char c = romanNum[i];
        while (i + 1 < romanNum.size() && c == romanNum[i + 1]) {
            count++;
            i++;
        }
        if (c == 'V'  || c == 'L' || c == 'D') {
            if (count > 1) {
                return false;
            }
        }
        if (c == 'I'  || c == 'X' || c == 'C' || c == 'M') {
            if (count > 3) {
                return false;
            }
        }
        count = 1;
        i++;
    }
    return true;
}

bool Validator::valid(std::string romanNum) {
    return validRomanNum(romanNum) && validRepitition(romanNum);
}
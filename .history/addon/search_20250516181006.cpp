#include <napi.h>
#include <iostream>
#include <vector>
#include <algorithm> 

#define NO_OF_CHARS 256

std::vector<int> goodSuffixHeuristic(const std::string& pattern) {

    int patternLength = pattern.size();

    std::vector<int> shift(patternLength + 1, 0);
    std::vector<int> border(patternLength + 1, 0);

    int i = patternLength;
    int j = patternLength + 1;
    border[i] = j;

    while (i > 0) {
        while (j <= patternLength && pattern[i - 1] != pattern[j - 1]) {
            if (shift[j] == 0) {
                shift[j] = j - i;
            }
            j = border[j];
        }
        --i; --j;
        border[i] = j;
    }

    j = border[0];
    for (i = 0; i <= patternLength; ++i) {
        if (shift[i] == 0) {
            shift[i] = j;
        }
        if (i == j) {
            j = border[j];
        }
    }

    return shift;
}

void badCharacterHeuristic(const std::string& pattern,
                                 int badCharTable[256]) {
    int patternLength = pattern.size();

    std::fill(badCharTable, badCharTable + 256, -1);

    for (int i = 0; i < patternLength; ++i) {
        badCharTable[static_cast<unsigned char>(pattern[i])] = i;
    }
}


std::vector<int> boyerMooreSearch(const std::string& text, const std::string& pattern) {

    int textLength = text.size();
    std::cout << "textLength" << textLength << std::endl;
    int patternLength = pattern.size();
    std::cout << "patternLength" << patternLength << std::endl;

    std::vector<int> result;

    if (patternLength == 0 || patternLength > textLength) {
        return result;
    }

    int badChar[NO_OF_CHARS];
    badCharacterHeuristic(pattern, badChar);
    std::vector<int> goodSuffix = goodSuffixHeuristic(pattern);
    std::cout << "goodSuffix: ";
    for (int val : goodSuffix) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    int shift = 0;  

    while (shift <= (textLength - patternLength)) {
        int j = patternLength - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            --j;
        }

        if (j < 0) {
            result.push_back(shift);
            shift += goodSuffix[0];  
        } else {
            int badCharShift = j - badChar[static_cast<unsigned char>(text[shift + j])];
            int goodSuffixShift = goodSuffix[j + 1];
            shift += std::max(1, std::max(badCharShift, goodSuffixShift));
        }
    }

    return result;
}





int main() {
    std::string text = "ababcabcababd";
    std::string pattern = "ababd";
    std::vector<int> positions = boyerMooreSearch(text, pattern);

    for (int pos : positions) {
        std::cout << "Pattern found at index: " << pos << std::endl;
    }

    return 0;
}

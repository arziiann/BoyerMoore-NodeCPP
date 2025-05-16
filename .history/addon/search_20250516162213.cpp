#include <iostream>
#include <vector>
#include <algorithm> 

#define NO_OF_CHARS 256

std::vector<int> goodSuffixHeuristic(const std::string& pattern);

void badCharacterHeuristic(const std::string& pattern, int badCharTable[256]) {
    int patternLength = pattern.size();

    std::fill(badCharTable, badCharTable + 256, -1);

    for (int i = 0; i < patternLength; ++i) {
        badCharTable[static_cast<unsigned char>(pattern[i])] = i;
    }
}


std::vector<int> boyerMooreSearch(const std::string& text, const std::string& pattern) {

    int textSize = text.size();
    int patternSize = pattern.size();

    int badchar[NO_OF_CHARS];



    return { };
}


int main() {
    

    badCharacterHeuristic("ABACD");
    // std::string text = "ababcabcabababd";
    // std::string pattern = "ababd";
    // std::vector<int> positions = boyerMooreSearch(text, pattern);

    // for (int pos : positions) {
    //     std::cout << "Pattern found at index: " << pos << std::endl;
    // }

    // return 0;
}
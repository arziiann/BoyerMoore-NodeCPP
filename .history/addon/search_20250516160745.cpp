#include <iostream>
#include <vector>

#define NO_OF_CHARS 256;

std::vector<int> goodSuffixHeuristic(const std::string& pattern);

std::unordered_map<char, int> badCharacterHeuristic(const std::string& pattern) {
    int patternSize = pattern.size();
    int arr[];

    for (int i = 0; i < patternSize; ++i) {
        arr[pattern[i]] = patternSize - i - 1;
    }

    for (int i = 0; i < patternSize; ++i) {
        arr[pattern[i]] = patternSize - i - 1;
    }

}


std::vector<int> boyerMooreSearch(const std::string& text, const std::string& pattern) {

    int textSize = text.size();
    int patternSize = pattern.size();

    int badchar[NO_OF_CHARS];



    return { };
}


int main() {
    std::string text = "ababcabcabababd";
    std::string pattern = "ababd";
    std::vector<int> positions = boyerMooreSearch(text, pattern);

    for (int pos : positions) {
        std::cout << "Pattern found at index: " << pos << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>


std::vector<int> boyerMooreSearch(const std::string& text, const std::string& pattern);
std::unordered_map<char, int> badCharacterHeuristic(const std::string& pattern);
std::vector<int> goodSuffixHeuristic(const std::string& pattern);

int main() {
    std::string text = "ababcabcabababd";
    std::string pattern = "ababd";
    std::vector<int> positions = boyerMooreSearch(text, pattern);

    for (int pos : positions) {
        std::cout << "Pattern found at index: " << pos << std::endl;
    }

    return 0;
}
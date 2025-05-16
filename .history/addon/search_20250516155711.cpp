#include <iostream>
#include <vector>


std::vector<int> boyerMooreSearch(const std::string& text, const std::string& pattern);
std::unordered_map<char, int> badCharacterHeuristic(const std::string& pattern);
std::vector<int> goodSuffixHeuristic(const std::string& pattern);

int main() {
    std::cout << "Hello World" << std::endl;
}
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
    int patternLength = pattern.size();

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


Napi::Value SearchWrapped(const Napi::CallbackInfo& info) {

    Napi::Env env = info.Env();

    std::string text = info[0].As<Napi::String>();
    std::string pattern = info[1].As<Napi::String>();

    std::vector<int> positions = boyerMooreSearch(text, pattern);

    Napi::Array result = Napi::Array::New(env, positions.size());
    for (size_t i = 0; i < positions.size(); ++i) {
        result[i] = Napi::Number::New(env, positions[i]);
    }

    return result;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("search", Napi::Function::New(env, SearchWrapped));
    return exports;
}

NODE_API_MODULE(search, Init)


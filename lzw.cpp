#include "lzw.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

std::vector<int> compress(const std::string& input) {
    std::map<std::string, int> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary[std::string(1, i)] = i;
    }

    std::string current;
    std::vector<int> result;
    for (char c : input) {
        std::string next = current + c;
        if (dictionary.find(next) != dictionary.end()) {
            current = next;
        }
        else {
            result.push_back(dictionary[current]);
            dictionary[next] = dictionary.size();
            current = std::string(1, c);
        }
    }

    if (!current.empty()) {
        result.push_back(dictionary[current]);
    }

    return result;
}

std::string decompress(const std::vector<int>& compressed) {
    std::map<int, std::string> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary[i] = std::string(1, i);
    }

    std::string result;
    std::string previous;
    for (int code : compressed) {
        std::string current;
        if (dictionary.find(code) != dictionary.end()) {
            current = dictionary[code];
        }
        else if (code == dictionary.size()) {
            current = previous + previous[0];
        }

        result += current;

        if (!previous.empty()) {
            dictionary[dictionary.size()] = previous + current[0];
        }

        previous = current;
    }

    return result;
}



std::vector<int> compress(const std::string& text) {
    std::vector<int> compressed;
    compressed = compress(text);
    return compressed;
}

std::string decompress(const std::vector<int>& compressed) {
    std::string decompressed = "";
    decompressed = decompress(compressed);
    return decompressed;
}

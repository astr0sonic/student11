#include "lzw.h"
#include <iostream>
#include <string>
#include <map>
#include<string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> compress_(const string& input) {
    map<string, int> dictionary={};
    for (int i = 0; i < 256; ++i) {
        dictionary[string(1, i)] = i;
    }

    string current="";
    vector<int> result;
    for (char c : input) {
        string next = current + c;
        if (dictionary.find(next) != dictionary.end()) {
            current = next;
        }
        else {
            result.push_back(dictionary[current]);
            dictionary[next] = dictionary.size();
            current = string(1, c);
        }
    }

    if (!current.empty()) {
        result.push_back(dictionary[current]);
    }

    return result;
}

string decompress_(const vector<int>& compressed_) {
    map<int, string> dictionary = {};
    for (int i = 0; i < 256; ++i) {
        dictionary[i] = string(1, i);
    }

    string result="";
    string previous(0);
    for (int code : compressed_) {
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



vector<int> compress(const string& text) {
    vector<int> compressed;
    compressed = compress_(text);
    return compressed;
}
string decompress(const vector<int>& compressed) {
    string decompressed = "";
    decompressed = decompress_(compressed);
    return decompressed;
}

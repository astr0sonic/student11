using namespace std;
#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include"lzw.h"



void testCompress(const string& inputFileName, const string& outputFileName) {
    using namespace std;
    ifstream in(inputFileName);
    string text = "";
    getline(in, text);
    in.close();

    vector<int> compressed_ = compress(text);

    ofstream out(outputFileName);
    out << compressed_[0];
    for (int i = 1; i < compressed_.size(); i++) {
        out << " " << compressed_[i];
    }
    out << endl;
    out.close();
}


void testDecompress(const string& inputFileName, const string& outputFileName) {
    using namespace std;
    ifstream in(inputFileName);
    vector<int> compressed_(0);
    int code = -1;
    while (in >> code) {
        compressed_.push_back(code);
    }
    in.close();

    string decompressed_ = decompress(compressed_);

    ofstream out(outputFileName);
    out << decompressed_ << endl;
    out.close();
}


int main(int argc, char** argv) {
    using namespace std;
    string inputFileName = argv[1];
    string outputFileName = argv[2];

    int len = inputFileName.length();
    bool isDecompress = static_cast<int>(inputFileName[len - 5]) - static_cast<int>('0') >= 4;
    if (isDecompress) {
        testDecompress(inputFileName, outputFileName);
    }
    else {
        testCompress(inputFileName, outputFileName);
    }

    return 0;
};




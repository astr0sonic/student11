#include <fstream>
#include <string>
#include <vector>
#include<iostream>
#include "lzw.h"

using namespace std;

void testCompress(const string& , const string& );
void testDecompress(const string& , const string& );


int main(int argc, char** argv) {
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


void testCompress(const string& inputFileName, const string& outputFileName) {
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

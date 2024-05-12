#include <string>
#include <map>
#include<queue>
#include<vector>
using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode* left, * right;
    MinHeapNode(char data, int freq);
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r);
};

std:: map<char, std::string> codes;
std:: map<char, int> freq;
std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> minHeap;





void storeCodes(struct MinHeapNode* root, std::string str);
void HuffmanCodes(int size);
void calcFreq(std::string str, int n);
std::string decode_file(struct MinHeapNode* root, std::string s);


std::string encode(const std::string& text);
std::string decode(const std::string& encoded, std::map<char, std::string>& codes);

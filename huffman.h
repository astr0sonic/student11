#include <string>
#include <map>
#include<queue>
#include<vector>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

vector<int> prefixFunction(string s);
vector<int> getIndices(const string& my_template, const string& text);
void storeCodes(struct MinHeapNode* root, std::string str);
void HuffmanCodes(int size);
void calcFreq(std::string str, int n);

string decodeHuffman(Node* , string& );
Node* buildHuffmanTree(map<char, string>& codes);

string encode(const string& text);
string decode(const string& encoded, map<char, string>& codes_);

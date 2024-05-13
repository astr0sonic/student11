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

void storeCodes(struct MinHeapNode* root, const string str);
void HuffmanCodes(int size);
void calcFreq(const string str, int n);

string decodeHuffman(Node* , const string );
Node* buildHuffmanTree(map<char, string>& codes);

string encode(const string& text);
string decode(const string& encoded, map<char, string>& codes_);

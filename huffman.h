#include <string>
#include <map>
#include<queue>
#include<vector>
using namespace std;


vector<int> prefixFunction(string s);
vector<int> getIndices(const string& my_template, const string& text);
void storeCodes(struct MinHeapNode* root, std::string str);
void HuffmanCodes(int size);
void calcFreq(std::string str, int n);
string decodeHuffman(Node* root, string& encodedStr);
Node* buildHuffmanTree(map<char, string>& codes);

std::string encode(const std::string& text);
std::string decode(const std::string& encoded, std::map<char, std::string>& codes_);

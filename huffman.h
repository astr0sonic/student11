#include <string>
#include <map>
#include<queue>
#include<vector>
using namespace std;




void storeCodes(struct MinHeapNode* root, std::string str);
void HuffmanCodes(int size);
void calcFreq(std::string str, int n);
std::string decode_file(struct MinHeapNode* root, std::string s);


std::string encode(const std::string& text);
std::string decode(const std::string& encoded, std::map<char, std::string>& codes);

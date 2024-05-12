#include "huffman.h"
#include<vector>
#include<map>
#include<string>
#include<queue>
#define MAX_TREE_HT 256
using namespace std;

map<char, string> codes;
map<char, int> freq;
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;



void storeCodes(struct MinHeapNode* root, string str)
{
    if (root == NULL)
        return;
    if (root->data != '$')
        codes[root->data] = str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}

void HuffmanCodes(int size)
{
    struct MinHeapNode* left, * right, * top;
    for (map<char, int>::iterator v = freq.begin();
        v != freq.end(); v++)
        minHeap.push(new MinHeapNode(v->first, v->second));
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$',
            left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}

void calcFreq(string str, int n)
{
    for (int i = 0; i < str.size(); i++)
        freq[str[i]]++;
}

string decode_file(struct MinHeapNode* root, string s)
{
    string ans = "";
    struct MinHeapNode* curr = root;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;


        if (curr->left == NULL && curr->right == NULL) {
            ans += curr->data;
            curr = root;
        }
    }

    return ans + '\0';
}

string encode(const string& text) {
    calcFreq(text, text.size());
    string encodedString;
    HuffmanCodes(text.size());
    for (int i=0;i< text.size(); i++)
        encodedString += codes[i];
    return encodedString
}

string decode(const string& encoded, map<char, string>& codes) {
   
    string decodedString;
    decodedString= decode_file(minHeap.top(), encoded);
    return  decodedString
}

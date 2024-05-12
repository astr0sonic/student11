#include "huffman.h"
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode* left, * right;

    MinHeapNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

map<char, string> codes={};
map<char, int> freq={};
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap={};


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
    for (map<char, int>::iterator v = freq.begin();v != freq.end(); v++)
        minHeap.push(new MinHeapNode(v->first, v->second));
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$',left->freq + right->freq);
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
    
}

vector<int> getIndices(const string& my_template, const string& text) {



    int pl = my_template.size();
    int tl = text.size();
    vector<int> answer(100);
    vector<int> pr = prefixFunction(my_template + "#" + text);
    int count = 0;
    for (int i = 0; i < tl; i++) {
        if (pr[pl + i + 1] == pl)
            answer[count++] = i - pl + 1;
    }
    vector<int> result(0);
    for (int i = 0; i < answer.size(); i++)
    {
        if (!(i > 0 && answer[i] == 0))
            result.push_back(answer[i]);
    }

    return result;
}

string encode(const string& text) {
    calcFreq(text, text.size());
    string encodedString=" ";
    HuffmanCodes(text.size());
    for (auto i : text)
        encodedString += codes[i];
    return encodedString;
}

string decode(const string& encoded, map<char, string>& codes_) {
   
    string decodedString=" ";
    decodedString= decode_file(minHeap.top(), encoded);
    return  decodedString;
}

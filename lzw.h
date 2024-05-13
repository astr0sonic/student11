#include<iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> compress_(const string& input);
string decompress_(const vector<int>& compressed_);
vector<int> compress(const string& text);
string decompress(const vector<int>& compressed);

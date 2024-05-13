#include <string>
#include <vector>
using namespace std; 

std::vector<int> compress(const std::string& text);
std::string decompress(const std::vector<int>& compressed);
std::vector<int> compress_(const std::string& input);
std::string decompress_(const std::vector<int>& compressed)
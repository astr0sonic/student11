#include "bracket.h"
#include <cstring>
using namespace std;

bool checkBrackets(const std::string& s) {
	const char* delim[2] = { "([{<", ")]}>" };
	string stack = "";
	for (int i = 0; i < s.size(); i++) {
		const char c = s[i];
		if (strchr(delim[0], c) != NULL) {
			stack.push_back(c);
			continue;
		}
		const char* z;
		if (NULL == (z = strchr(delim[1], c)))
			continue;
		if (stack.empty() || stack.back() != delim[0][z - delim[1]])
			return false;
		stack.pop_back();
	}
	return stack.empty();
}

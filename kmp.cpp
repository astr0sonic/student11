#include "kmp.h"
#include<vector>
using namespace std;


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
    vector<int> result(2, 0);
    for (int i = 0; i < answer.size(); i++)
    {
        if (!(i > 0 && answer[i] == 0))
            result.push_back(answer[i]);
    }
    
    return result;
}

vector<int> prefixFunction(string s) {
    vector<int> p(100);
    p[0] = 0;
    int k = 0;
    for (int i = 1; i < s.size(); i++) {
        k = p[i - 1];
        while (k > 0 && s[i] != s[k])
            k = p[k - 1];
        if (s[i] == s[k])
            k++;
        p[i] = k;
    }
    return p;
}
#include "rpn.h"
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;

double calculateRPN(const std::string& expr) {
	stack<double> st;
	int i = 0;
	double x = 0;
	double y = 0;

	while (i != expr.size())
	{

		if (i != expr.size() && isdigit(expr[i])) {
			st.push(expr[i] - '0');

		}
		else
		{
			if (expr[i] == '+') {
				x = st.top();
				st.pop();
				y = st.top();
				st.pop();
				st.push(x + y);
			}

			if (expr[i] == '-') {
				x = st.top();
				st.pop();
				y = st.top();
				st.pop();
				st.push(y - x);
			}

			if (expr[i] == '*') {
				x = st.top();
				st.pop();
				y = st.top();
				st.pop();
				st.push(x * y);
			}

			if (expr[i] == '/') {
				x = st.top();
				st.pop();
				y = st.top();
				st.pop();
				st.push(y / x);
			}



		}
		i++;


		return st.top();

	}
}
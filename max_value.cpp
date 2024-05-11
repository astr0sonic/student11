#include "max_value.h"
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;

double calculateMaxValue(double* nums, int n) {
	vector<double> v(n);
	for (int i = 0; i < n; i++)
		v[i] = nums[i];
	
	double result = myFunction(v);
	return result;
	
}

double myFunction(vector<double> v) {
	double mx = v[0];
	double mn = mx;
	vector<double> rez;

	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] != 0) {
			rez = vector<double>{ mx - v[i],mx + v[i],mx * v[i],mx / v[i],mn - v[i],mn + v[i],mn * v[i],mn / v[i] };
			sort(rez.begin(), rez.end());
			mn = rez[0];
			mx = rez[rez.size() - 1];
		}
	}
	return mx;


}
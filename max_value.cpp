#include "max_value.h"


double calculateMaxValue(double* nums, int n) {
	
	ifstream f("input.txt");
	for (int i = 0; i < n; i++)
		f << nums[i];
	result = myFunction(f);
	return result;
}

double myFunction(ifstream& f) {
	vector<double> v;
	for (int i = 0; !f.eof(); i++)
		f >> v[i];
	double mx = v[0];
	double mn = mx;
	int x = v.size();
	vector<double> rez;
	for (int i = 1; i < x; i++)
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
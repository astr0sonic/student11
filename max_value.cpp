#include "max_value.h"
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;

double calculateMaxValue(double* nums, int n) {
	
	ofstream f("output.txt");
	for (int i = 0; i < n; i++)
		f << nums[i]<<endl;
	f.close();

	ifstream f_1("output.txt");
	double result = myFunction(f_1);
	return result;
}

double myFunction(ifstream& f) {
	vector<double> v;
	double x;
	for (int j = 0; !f.eof(); j++) {
		if(f>>x!=' ')
			v[j]=x;
	}
	f.close();

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
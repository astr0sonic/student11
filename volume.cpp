#include"volume.h"
#include<vector>
#include<algorithm>

using namespace std;

int getMaxVolume(int a, int b, int c, int n, int* arr) {
	vector<int> max_vol(1);

	int h = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] <= arr[j])
				h = arr[i];
			else
				h = arr[j];

			if ((b * (j - i) * h) <= (a * b * c) && (j - i) <= a && h <= c) {
				max_vol.push_back(b * (j - i) * h);

			}

		}
	}

	sort(max_vol.begin(), max_vol.end());
	int x = max_vol[max_vol.size() - 1];
	return  x;
}

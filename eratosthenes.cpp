#include "eratosthenes.h"
#include<vector>
using namespace std;

std::vector<int> sieve(int n) {
	vector<bool> primes(n, true);
	vector<int> prime;
	for (int i = 1; i < n; i++)
	{
		if (primes[i])
			for (int j = 2 * i + 1; j < n; j += i + 1)
				primes[j] = false;
	}
	for (int i = 1; i < primes.size(); i++)
	{
		if (primes[i])
			prime.push_back(i + 1);
	}
    return prime;
}

#include "sundaram.h"

std::vector<int> sieve(int n) {
    std::vector<int> primes;
    primes.push_back(2);
    std::vector<bool> p(n);
    for (int i = 1; 3 * i + 1 < n; i++)
        for (int j = 1; i + j + 2 * i * j < n && j <= i; j++)
            p[i + j + 2 * i * j] = 1;

    for (int i = 1; i < n && (2 * i + 1) <= n; i++)
        if (p[i] == 0)
            primes.push_back(2 * i + 1);
    return primes;
}
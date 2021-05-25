// raj_orton

// Tested on : https://www.spoj.com/problems/TDKPRIME/

#include <bits/stdc++.h>
using namespace std;

struct Sieve {
    int n;
    vector<bool> isPrime;
    Sieve(int n_ = 1000000) {
        n = n_;
        isPrime.resize(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    vector<int> getPrimes() {
        vector<int> primes;
        for (int i = 0; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }
    bool queryPrime(int x) {
        assert(0 <= x && x <= n);
        return isPrime[x];
    }
};

int32_t main() {
    Sieve sieve(90000000);
    auto prime = sieve.getPrimes();
    int t;
    cin >> t;
    while (t-- > 0) {
        int k;
        cin >> k;
        printf("%d\n", prime[k - 1]);
    }
    return 0;
}

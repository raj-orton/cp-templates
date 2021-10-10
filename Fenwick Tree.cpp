#include <bits/stdc++.h>
using namespace std;

template <typename Type>
struct FenwickTree {
    int n;
    vector<Type> ft;
    
    FenwickTree(int n_ = 100000) {
        n = n_;
        ft.resize(n + 1);
    }

    Type get(int idx) {
        Type ans = 0LL;
        for(; idx; idx -= (idx & -idx))
            ans += ft[idx];
        return ans;
    }

    Type get(int L, int R) {
        return (get(R) - get(L - 1));
    }

    void add(int idx, Type val) {
        for(; idx <= n; idx += (idx & -idx))
            ft[idx] += val;
    }
};

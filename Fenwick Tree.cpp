#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> ft;

long long query(int idx) {
    long long ans = 0LL;
    for(; idx; idx -= (idx & -idx))
        ans += ft[idx];
    return ans;
}

long long rangeQuery(int L, int R) {
    return (query(R) - query(L - 1));
}

void update(int idx, long long val) {
    for(; idx <= n; idx += (idx & -idx))
        ft[idx] += val;
}

void build() {
    ft.resize(n + 3, 0);
    vector<long long> a(n + 3);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    /*
    1-based indexing
    build();
    update(index, value);
    query(index); //Gives from 1 - index
    */

	return 0;
}

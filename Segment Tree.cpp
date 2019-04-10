#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
vector<long long> a(N);
vector<long long> tree(4 * N);
int n;

long long query(int L, int R, int cur = 1, int l = 1, int r = n) {
    if(L > r || l > R)
        return 0;
    if(L <= l && r <= R)
        return tree[cur];
    int m = (l + r) / 2;
    return (query(L, R, 2 * cur, l, m) + query(L, R, 2 * cur + 1, m + 1, r));
}

void update(int idx, long long val, int cur = 1, int l = 1, int r = n) {
    if(l == r)
        a[idx] = tree[cur] = val;
    else {
        int m = (l + r) / 2;
        if(idx <= m)
            update(idx, val, 2 * cur, l, m);
        else
            update(idx, val, 2 * cur + 1, m + 1, r);
        tree[cur] = tree[2 * cur] + tree[2 * cur + 1];
    }
}

void build(int cur = 1, int l = 1, int r = n) {
    if(l == r)
        tree[cur] = a[l];
    else {
        int m = (l + r) / 2;
        build(2 * cur, l, m);
        build(2 * cur + 1, m + 1, r);
        tree[cur] = tree[2 * cur] + tree[2 * cur + 1];
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    /*
    1-based indexing
    build();
    update(index, value);
    query(from, to);
    */

	return 0;
}

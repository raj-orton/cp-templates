#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
const int logN = 5;
const long long INF = (1LL << 40);
vector<long long> a(N);
long long st[N][logN];
int n;

long long f(long long a, long long b) {
    return a + b;
}

long long queryConstant(int l, int r) {
    int floorLog = (int) floor(log((double)r - l + 1) / log(2.0));
    return f(st[l][floorLog], st[r - (1 << floorLog) + 1][floorLog]);
}

long long queryLog(int l, int r) {
    long long ans = 0LL;
    for(int floorLog = (int) floor(log((double)r - l + 1) / log(2.0)); floorLog >= 0; floorLog--)
        if(l + (1 << floorLog) - 1 <= r)
            ans += st[l][floorLog], l = l + (1 << floorLog);
    return ans;
}

void build() {
     for(int j = 0; j < logN; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] = (j == 0 ?a[i] :f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]));
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    /*
    1-based indexing
    build();
    queryConstant(from, to);
    queryLog(from, to);
    */

    return 0;
}

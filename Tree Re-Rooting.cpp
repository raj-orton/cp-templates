// tree re-rooting techique
// CF - 1324F (Maximum White Subtree)

// raj_orton

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int inf = 1e6;
const int N = 2e5 + 5;
int n;
int a[N];
vector<int> adj[N];

int ans[N], dp[N];

void dfs(int cur, int prv) {
	dp[cur] = a[cur];
	for(int nxt : adj[cur]) {
		if(nxt == prv) continue;
		dfs(nxt, cur);
		dp[cur] += max(0LL, dp[nxt]);
	}
}

void run(int cur, int prv) {
	ans[cur] = dp[cur];
	for(int nxt : adj[cur]) {
		if(nxt == prv) continue;
		dp[cur] -= max(0LL, dp[nxt]);
		dp[nxt] += max(0LL, dp[cur]);
		run(nxt, cur);
		dp[nxt] -= max(0LL, dp[cur]);
		dp[cur] += max(0LL, dp[nxt]);
	}
}

void solve() {
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] == 0) a[i] = -1;
	}
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 0; i < n; i++) {
		ans[i] = -inf;
	}
	
	dfs(0, 0);
	run(0, 0);
	
	for(int i = 0; i < n; i++) {
		cout << ans[i] << " \n"[i == n - 1];
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
	// int t; cin >> t; for(int i = 1; i <= t; i++) //cout << "Case #" << i << ": ",
	solve();
	return 0;
}

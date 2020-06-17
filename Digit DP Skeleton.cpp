// ராஜ்_ஆர்ட்டன்

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

// gives cnt[0, r] - cnt[0, l - 1]

const int N = 105, mod = 1e9 + 7;
string s[2];
int n[2];
int digit[2][N];
int dp[2][2][N];

int go(int x, int equal, int i) {
	if(i == n[x]) {
		return 1;
	}
	
	int &ans = dp[x][equal][i];
	if(ans != -1) return ans;
	
	ans = 0;
	if(equal == 0) {
		for(int j = 0; j <= 9; j++) {
			ans += go(x, 0, i + 1);
			ans %= mod;
		}
	} else {
		for(int j = 0; j <= digit[x][i]; j++) {
			if(j < digit[x][i]) ans += go(x, 0, i + 1);
			else ans += go(x, 1, i + 1);
			ans %= mod;
		}
	}
	return ans;
}

void solve() {
	
	for(int i = 0; i < 2; i++) {
		cin >> s[i];
		n[i] = s[i].size();
		for(int j = 0; j < n[i]; j++) {
			digit[i][j] = s[i][j] - '0';
			cerr << digit[i][j] << " \n"[j == n[i] - 1];
		}
	}
	
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			for(int k = 0; k < n[i]; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	
	for(int i = 0; i < 2; i++) {
		cerr << go(i, 1, 0) << endl;
	}
	
	cout << (go(1, 1, 0) - go(0, 1, 0) + mod) % mod << endl;
	
	
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
	// int t; cin >> t; for(int i = 1; i <= t; i++) //cout << "Case #" << i << ": ",
	solve();
	return 0;
}

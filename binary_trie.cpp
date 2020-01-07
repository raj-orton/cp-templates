#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int B = 32;
const int NB = N * B;

class binary_trie {
    public:
        int nxt[NB][2], cnt[NB], id, root;
        binary_trie() {
            for(int i = 0; i < NB; i++)
                cnt[i] = nxt[i][0] = nxt[i][1] = 0;
            id = 1, root = 0;
        }
        void insert(int x) {
            int p = root;
            for(int i = 30; i >= 0; i--) {
                int b = (x >> i) & 1;
                if( !nxt[p][b] ) nxt[p][b] = id++;
                p = nxt[p][b];
                cnt[p]++;
            }
        }
        void erase(int x) {
            int p = root;
            for(int i = 30; i >= 0; i--) {
                int b = (x >> i) & 1;
                p = nxt[p][b];
                cnt[p]--;
            }
        }
        int max_xor(int x) {
            int p = root, ans = 0;
            for(int i = 30; i >= 0; i--) {
                int b = (x >> i) & 1;
                if( cnt[nxt[p][!b]] )
                    ans |= (1 << i), p = nxt[p][!b];
                else
                    p = nxt[p][b];
            }
            return ans;
        }
};

int main() {

	binary_trie trie;
	trie.insert(0);
	int q;
	cin >> q;
	while( q-- ) {
	    char c; int x;
	    cin >> c >> x;
	    if(c == '+')
	        trie.insert(x);
	    else if(c == '-')
	        trie.erase(x);
	    else
	        cout << trie.max_xor(x) << endl;
	}

    return 0;
}

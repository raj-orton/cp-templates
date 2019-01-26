#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define pii pair<lli, lli>

class disjoint_set
{
    public :
        vector<int> r, p;

        disjoint_set(int n) {
            r.resize(n+5, 0);
            p.resize(n+5);
            for(int i = 0; i <= n; i++)
                p[i] = i;
        }

        int find_set(int i) {
            return (p[i] == i) ?i :(p[i] = find_set(p[i]));
        }

        int same_set(int i, int j) {
            return find_set(i) == find_set(j);
        }

        void union_set(int i, int j) {
            if(!same_set(i, j)) {
                int x = find_set(i), y = find_set(j);
                if(r[y] < r[x])
                    p[y] = x;
                else {
                    p[x] = y;
                    if(r[x] == r[y])
                        r[y]++;
                }
            }
        }

};

int main()
{

    

    return 0;
}

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

constexpr int size = 100001;
bool visited[size] = {false};
int ans[size*2];
int l = size, r = size + 1;

int main() {
    int N, M, a, b;
    scanf("%d %d\n", &N, &M);
    vector<vector<int>> G(N + 1, vector<int>(0));
    REP(i, M) {
        scanf("%d %d\n", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int s = 1, t = G[s][0];
    ans[l] = s; ans[r] = t;
    visited[s] = visited[t] = true;
    bool fs = true, ft = true;
    while(fs || ft) {
        if(fs) {
            fs = false;
            for(auto& x : G[s]) {
                if(!visited[x]) {
                    s = x; fs = true;
                    ans[--l] = s;
                    break;
                }
            }
            visited[s] = true;
        }
        if(ft) {
            ft = false;
            for(auto& x : G[t]) {
                if(!visited[x]) {
                    t = x; ft = true;
                    ans[++r] = t;
                    break;
                }
            }
            visited[t] = true;
        }
    }
    printf("%d\n", r - l + 1);
    while(l <= r) printf("%d ", ans[l++]);
    printf("\n");
	return 0;
}

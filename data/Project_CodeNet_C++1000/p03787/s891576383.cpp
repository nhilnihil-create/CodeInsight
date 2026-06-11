#include "bits/stdc++.h"
using namespace std;

#define all(x)  x.begin(), x.end()
#define mp      make_pair
#define pii     pair<int, int>
#define pll     pair<long long, long long>
#define ll      long long

vector<int> g[101010];
int color[101010];

bool dfs(int v, int prev, int c) {
        color[v] = c;
        bool bipartite = true;
        for (auto u : g[v]) if (u != prev) {
                if (color[u] == -1) {
                        if (!dfs(u, v, 1 - c)) bipartite = false;
                } else if (color[u] != 1 - c) {
                        bipartite = false;
                }
        }
        return bipartite;
}

int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i ++) {
                int a, b;
                scanf("%d%d", &a, &b);
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        long long cntA = 0, cntB = 0, cntC = 0;
        for (int i = 0; i < n; i ++) color[i] = -1;
        for (int i = 0; i < n; i ++) {
                if (color[i] == -1) {
                        if (g[i].size() == 0) {
                                cntA ++;
                                continue;
                        }
                        if (dfs(i, -1, 0)) cntB ++;
                        else cntC ++;
                }
        }
        long long ans = cntA * cntA + (n - cntA) * cntA * 2 + cntB * cntB * 2 + cntB * cntC * 2 + cntC * cntC;
        printf("%lld\n", ans);
        return 0;
}


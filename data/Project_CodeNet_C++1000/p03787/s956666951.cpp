#include "bits/stdc++.h"
using namespace std;

#define all(x)  x.begin(), x.end()
#define mp      make_pair
#define pii     pair<int, int>
#define pll     pair<long long, long long>
#define ll      long long

vector<int> g[101010];

int color[101010]; //initialized to -1

int bipartite_graph(int v, int prev, int c) {
        color[v] = c;
        int cnt = c;
        bool ok = true;
        for (auto u : g[v]) if (u != prev) {
                if (color[u] == -1) {
                        int get = bipartite_graph(u, v, 1 - c);
                        if (get == -1) ok = false;
                        cnt += get;
                } else if (color[u] != 1 - c) {
                        ok = false;
                }
        }
        if (!ok) return -1;
        return cnt;
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
                        if (g[i].size() == 0) cntA ++;
                        else if (bipartite_graph(i, -1, 0) != -1) cntB ++;
                        else cntC ++;
                }
        }
        long long ans = cntA * cntA + (n - cntA) * cntA * 2 + cntB * cntB * 2 + cntB * cntC * 2 + cntC * cntC;
        printf("%lld\n", ans);
        return 0;
}


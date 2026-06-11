#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <set>
#include <map>

using namespace std;

const int oo = 23041997, maxN = 2e5 + 10, modP = 1e9 + 7;

#define FORU(i, l, r) for (int i = l; i <= r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPU(i, r) for (int i = 0; i < r; ++i)
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PINT pair < int, int >
#define BIT(x, i) ((x >> i) & 1)
#define NUM_SET_BIT __builtin_popcountll

int c[maxN][2], n, k, m, q[maxN], flag;
vector < int > adj[maxN];
map < PINT, int > mmap;

void bfs(int u, int t) {
    int l = 1, r = 1;
    q[1] = u; 
    c[u][t] = ++flag;
    while (l <= r) {
        int u = q[l++];
        c[u][t] = flag;
        REPU(i, adj[u].size()) {
            int v = adj[u][i];
            if (c[v][t]) continue;
            c[v][t] = flag;
            q[++r] = v;
        }
    }
}

int main() {
    cin >> n >> k >> m;
    FORU(i, 1, k) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].PB(v);
        adj[v].PB(u);
    }

    FORU(i, 1, n)
        if (!c[i][0]) bfs(i, 0);

    flag = 0;
    FORU(i, 1, n) adj[i].clear();
    FORU(i, 1, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].PB(v);
        adj[v].PB(u);
    }

    FORU(i, 1, n)
        if (!c[i][1]) bfs(i, 1);

    FORU(i, 1, n) mmap[MP(c[i][0], c[i][1])]++;
    FORU(i, 1, n) printf("%d ", mmap[MP(c[i][0], c[i][1])]);
}

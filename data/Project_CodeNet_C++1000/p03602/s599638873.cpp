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
#include <unordered_map>

using namespace std;

const int maxN =  400, BASE = 1e9 + 7;
const long long oo = 10000000000000ll;

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

struct cmp {
    bool operator () (pair < int, LL > a, pair < int, LL > b) {
        return b.S < a.S;
    }
};

priority_queue < pair < int, LL >, vector < pair < int, LL > >, cmp > heap;

int n, c[maxN][maxN], a[maxN][maxN], check[maxN];
vector < pair < int, PINT > > e;
vector < PINT > adj[maxN];
LL res, d[maxN];

LL dijkstra(int s, int t) {
    FORU(i, 1, n) d[i] = oo, check[i] = 0;
    while (!heap.empty()) heap.pop();
    d[s] = 0; heap.push(MP(s, d[s]));

    while (!heap.empty()) {
        auto p = heap.top(); heap.pop();
        while (check[p.F] && !heap.empty()) {
            p = heap.top();
            heap.pop();
        }
        if (check[p.F]) break;

        int u = p.F;
        if (u == t) return d[t];
        REPU(i, adj[u].size()) {
            int v = adj[u][i].F;
            int w = adj[u][i].S;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                heap.push(MP(v, d[v]));
            }
        }
    }

    return (d[t] == oo) ? -1 : d[t];
}

int main() {
    cin >> n;
    FORU(i, 1, n)
        FORU(j, 1, n) {
            int x; scanf("%d", &x);
            if (j <= i) continue;
            e.PB({x, MP(i, j)});
        }

    sort(e.begin(), e.end());

    for (auto p : e) {
        int u = p.S.F;
        int v = p.S.S;
        int w = p.F;
        int len = dijkstra(u, v);
        if ((len != -1 && len < w) || (len > w && c[u][v])) {
            cout << -1;
            return 0;
        }
        if (len != w) {
            c[u][v] = c[v][u] = w;
            res += w;
            adj[u].PB(MP(v, w));
            adj[v].PB(MP(u, w));
        }
    }

    cout << res;
}

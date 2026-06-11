#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct UnionFind {
    static constexpr int M = 1 << 30;
    UnionFind(int n) : p(n, -1), r(n) {}
    int root(int u) {
        if (p[u] < 0) return u;
        int v = p[u] & ~M, m = p[u] & M;
        return p[u] = root(v) ^ m;
    }
    bool same(int u, int v) {
        return ((root(u) ^ root(v)) & ~M) == 0;
    }
    void unite(int u, int v) {
        u = root(u);
        v = root(v);
        if (((u ^ v) & ~M) == 0) {
            if (u == v) p[u & ~M] = -2; // 二部グラフでない
            return;
        }
        int m = (u & M) ^ (v & M) ^ M;
        u &= ~M; v &= ~M;
        if (r[u] > r[v]) swap(u, v);
        p[v] = min(p[u], p[v]);
        p[u] = v ^ m;
        r[v] += (r[u] == r[v]);
    }
    vector<int> p, r;
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        uf.unite(u, v);
    }

    int64_t k[3] = {};
    for (int i = 0; i < n; i++) {
        if (uf.p[i] < 0) k[(uf.r[i] > 0) + (uf.p[i] != -1)]++;
    }

    k[2] += k[1];
    int64_t r = k[0] * (n * 2 - k[0]) + k[2] * k[2] + k[1] * k[1];

    cout << r << endl;

    return 0;
}

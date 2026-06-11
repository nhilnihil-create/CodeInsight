#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct UnionFind {
    UnionFind(int n) : p(n, -1), r(n) {}
    int root(int u) {
        return p[u] < 0 ? u : p[u] = root(p[u]);
    }
    bool same(int u, int v) {
        return root(u) == root(v);
    }
    void unite(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) return;
        if (r[u] > r[v]) swap(u, v);
        p[u] = v;
        r[v] += (r[u] == r[v]);
    }
    vector<int> p, r;
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n * 2);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        uf.unite(u, v + n);
        uf.unite(u + n, v);
    }

    int64_t k[3] = {};
    for (int i = 0; i < n * 2; i++) {
        if (uf.p[i] >= 0) continue;
        if (uf.r[i] == 0) k[0]++;
        else {
            int v = i < n ? i + n : i - n;
            k[1 + uf.same(i, v)]++;
        }
    }

    k[0] /= 2;
    k[1] /= 2;
    k[2] += k[1];
    int64_t r = k[0] * (n * 2 - k[0]) + k[2] * k[2] + k[1] * k[1];

    cout << r << endl;

    return 0;
}

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct UnionFind {
    vector<int> d;
    UnionFind(int n = 0) : d(n,-1) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -d[find(x)]; }
};

int main() {
    UnionFind uf(12);
    uf.unite(1, 3);
    uf.unite(3, 5);
    uf.unite(5, 7);
    uf.unite(7, 8);
    uf.unite(8, 10);
    uf.unite(10, 12);
    uf.unite(4, 6);
    uf.unite(6, 9);
    uf.unite(9, 11);
    int x, y;
    cin >> x >> y;
    if (uf.same(x, y)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

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
    int n, k, l;
    cin >> n >> k >> l;
    UnionFind road(n);
    UnionFind railway(n);
    for (int i = 0; i < k; ++i) {
        int p, q;
        cin >> p >> q;
        --p; --q;
        road.unite(p, q);
    }
    for (int j = 0; j < l; ++j) {
        int r, s;
        cin >> r >> s;
        --r; --s;
        railway.unite(r, s);
    }
    map<pair<int, int>, int> ma;
    for (int v = 0; v < n; ++v) {
        pair<int, int> p(road.find(v), railway.find(v));
        ma[p]++;
    }
    for (int v = 0; v < n; ++v) {
        pair<int, int> p(road.find(v), railway.find(v));
        cout << ma[p] << " ";
    }
    cout<< endl;
}

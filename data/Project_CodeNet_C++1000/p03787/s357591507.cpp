// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, r) for (int i = (l); i < (r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <class T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <class T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Union-Find
struct UnionFind {
    vector<int> par;
    UnionFind(int N) : par(N, -1) { }
    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (par[rx] > par[ry]) swap(rx, ry);
        par[rx] += par[ry];
        par[ry] = rx;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        return -par[root(x)];
    }
};

// Main Code
int main() {
    int n, m;
    cin >> n >> m;
    
    UnionFind uf1(n), uf2(n * 2);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        uf1.unite(u, v);
        uf2.unite(u + n, v); uf2.unite(u, v + n);
    }
    
    vector<bool> vec(n, true);
    vector<int> siz(n, 0);
    rep(i, n) {
        if (uf2.same(i, i + n)) vec[uf1.root(i)] = false;
        ++siz[uf1.root(i)];
    }
    ll a = 0, b = 0;
    rep(i, n) {
        if (siz[i] > 1) {
            ++b;
            if (vec[i]) ++a;
        }
    }
    ll c = n;
    rep(i, n) {
        if (uf1.size(i) == 1) --c;
    }
    
    cout << (ll)n * n - c * c + b * b + a * a << "\n";
    return 0;
}

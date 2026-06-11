#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (size_t i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)

const static int MOD = 1000000000 + 7;
const static llong INF = 1LL << 60;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};

struct UF {
    vector<int> par, sz;

    UF(int n) {
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find_root(int x) {
        return par[x] == x ? x : par[x] = find_root(par[x]);
    }

    bool same(int x, int y) {
        return find_root(x) == find_root(y);
    }

    void unite(int x, int y) {
        x = find_root(x);
        y = find_root(y);
        if (x == y) return;
        
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
};

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k, l;
    cin >> n >> k >> l;
    UF road(n), rail(n);
    rep(i, k) {
        int p, q;
        cin >> p >> q;
        road.unite(p - 1, q - 1);
    }
    rep(i ,l) {
        int r, s;
        cin >> r >> s;
        rail.unite(r - 1, s - 1);
    }

    vector<pair<int, int> > V(n);
    map<pair<int, int>, int> M;
    rep(i, n) {
        V[i].first = road.find_root(i);
        V[i].second = rail.find_root(i);
        ++M[V[i]];
    }

    rep(i, n) {
        if (i) cout << " ";
        cout << M[V[i]];
    }
    cout << endl;

    return 0;
}
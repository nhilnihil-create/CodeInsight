#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
typedef pair<int, int> pint;
int N, K, L;

struct UnionFind {
    vector<int> par;

    UnionFind(int n)
        : par(n, -1)
    {
    }
    void init(int n) { par.assign(n, -1); }

    int root(int x)
    {
        if (par[x] < 0) {
            return x;
        } else {
            return par[x] = root(par[x]);
        }
    }

    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }

    bool merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y) {
            return false;
        }
        if (par[x] > par[y]) {
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x)
    {
        return -par[root(x)];
    }
};

signed main()
{
    cin >> N >> K >> L;
    UnionFind uf1(N), uf2(N);
    rep(i, K)
    {
        int p, q;
        cin >> p >> q;
        --p, --q;
        uf1.merge(p, q);
    }
    rep(i, L)
    {
        int r, s;
        cin >> r >> s;
        --r, --s;
        uf2.merge(r, s);
    }
    map<pint, int> mp;
    rep(i, N)
    {
        pint p(uf1.root(i), uf2.root(i));
        ++mp[p];
    }
    rep(i, N)
    {
        pint p(uf1.root(i), uf2.root(i));
        cout << mp[p] << " ";
    }
    cout << endl;
    return 0;
}
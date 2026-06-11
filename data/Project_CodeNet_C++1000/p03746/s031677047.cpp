#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

struct UnionFind {
    UnionFind() {}
    UnionFind(int n) {
        resize(n);
    }
    
    void resize(int n) {
        par.resize(n, -1);
    }
    
    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    
    bool merge(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return false;
        if (par[rx] > par[ry]) swap(rx, ry);
        par[rx] += par[ry];
        par[ry] = rx;
        return true;
    }
    
    bool is_same(int x, int y) {
        return (root(x) == root(y));
    }
    
    int size(int x) {
        return -par[root(x)];
    }
    
private:
    vector<int> par;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    deque<ll> dq;
    dq.push_back(0);
    dq.push_back(g[0][0]);
    UnionFind uf(n);
    uf.merge(0, g[0][0]);
    while(true) {
        bool updated = false;
        ll st = dq[0], en = dq[sz(dq) - 1];
        for(auto &x : g[st]) {
            if (uf.root(st) == uf.root(x)) continue;
            uf.merge(st, x);
            dq.push_front(x);
            updated = true;
            break;
        }
        for(auto &x : g[en]) {
            if (uf.root(en) == uf.root(x)) continue;
            uf.merge(en, x);
            dq.push_back(x);
            updated = true;
            break;
        }
        if (!updated) break;
    }
    printf("%lld\n", sz(dq));
    rep(i, sz(dq)) printf("%lld%s", dq[i] + 1, (i == (sz(dq) - 1)) ? "\n" : " ");
    return 0;
}

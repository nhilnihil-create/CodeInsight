//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define V vector
template <typename T> bool chmin(T &a, const T &b) {if(a > b){a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T &b) {if(a < b){a = b; return true;} return false;}
template<typename A, size_t N, typename T> void Fill (A (&array)[N], const T & val) {fill ((T*)array, (T*)(array+N), val);}
V<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};
V<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};

V<V<P>> to(1e5+5);
V<ll> dk(1e5+5, -1);

void dfs (int now, int p, ll cost) {//nowの親はp
    dk[now] = cost;
    for (auto nxt : to[now]) {
        if (nxt.first == p) continue;
        dfs(nxt.first, now, cost + nxt.second);
    }
}

int main () {
    int n; cin >> n;
    rep(i, n-1) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        to[a].emplace_back(b, c); to[b].emplace_back(a, c);
    }
    int q, k; cin >> q >> k; k--;
    dfs(k, -1, 0);
    rep(i, q) {
        int x, y; cin >> x >> y; x--; y--;
        printf("%ld\n", dk[x] + dk[y]);
    }

    return 0;
}
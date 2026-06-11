#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

vvl G;
vl dp;  // dp[v] : vを根とする部分木のトーナメントの深さの最小値

void dfs(ll v, ll p = -1) {
    // 行きの処理はこのへんに書く
    vl vec;  // vの子のdp値を要素とするvector
    for(auto u : G[v]) {
        if(u == p) {
            continue;
        }
        dfs(u, v);
        // 帰りの処理はこのへんに書く
        vec.pb(dp[u]);
    }
    if(vec.size() == 0) {  // 葉のときのdpの値は0
        dp[v] = 0;
    }
    else {
        sort(rall(vec));
        rep(i, vec.size()) {
            chmax(dp[v], vec[i] + i+1);
        }
    }
}

int main() {
    ll n;
    cin >> n;

    vl a(n);
    exrep(i, 1, n-1) {
        cin >> a[i];
        a[i]--;
    }

    G.resize(n);
    exrep(v, 1, n-1) {
        G[v].pb(a[v]);
        G[a[v]].pb(v);
    }

    dp.resize(n);
    const ll root = 0;
    dfs(root);

    out(dp[root]);
    re0;
}
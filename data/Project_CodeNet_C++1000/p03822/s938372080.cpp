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
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
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

ll dfs(ll v) {
    vl a;
    for(auto u : G[v]) {
        a.pb(dfs(u));
    }
    sort(all(a));
    ll x = 0;
    rep(i, a.size()) {
        chmax(x, a[i]) + 1;
    }
    return x;
}

int main() {
    ll n;
    cin >> n;

    G.resize(n);
    exrep(i, 1, n-1) {
        ll v;
        cin >> v;
        v--;
        G[v].pb(i);
    }
    
    out(dfs(0));
    re0;
}
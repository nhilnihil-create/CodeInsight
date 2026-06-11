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
vl dp;  // dp[v] : 人vに対応する頂点を根とした部分木のトーナメントの深さの最小値
 
void dfs(ll v) {
    vl x;  // vの子のdp値を入れるvector
    dp[v] = G[v].size();  // 少なくとも子の数以上の深さは必要
    for(auto u : G[v]) {
        dfs(u);
        x.pb(dp[u]);
    }
    sort(rall(x));
    rep(i, G[v].size()) {
        chmax(dp[v], x[i] + i+1);
    }
}
 
int main() {
    ll n;
    cin >> n;
    
    G.resize(n);
    rep(i, n-1) {
        ll v;
        cin >> v;
        v--;
        G[v].pb(i+1);
    }

    dp.resize(n);
    dfs(0);
    
    out(dp[0]);
    re0;
}
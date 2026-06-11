#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG_ 
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

int main(void) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    vector<vector<ll>> g(n);
    REP(i, n-1) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(n == 2) {
        if(a[0] == a[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }

    function<ll(ll,ll)> dfs = [&](ll v, ll p) {
        ll sum = 0, max = -INF;
        vector<ll> ch_val;
        for(auto to: g[v]) if(to != p) {
            ll val = dfs(to, v);
            sum += val;
            chmax(max, val);
            ch_val.push_back(val);
        }
        if(ch_val.size() == 0) return a[v];
        // どうがんばってもペアをつくれない
        if((sum+1)/2 > a[v] || a[v] > sum) {
            cout << "NO" << endl;
            exit(0);
        }
        ll rest = (a[v] - (sum+1)/2)*2 + sum%2;
        // a[v]-rest 個のペアをつくれない
        if(max-rest > (sum-rest)/2) {
            cout << "NO" << endl;
            exit(0);
        } 
        return rest;
    };

    ll root = -1;
    REP(i, n) if(g[i].size() >= 2) root = i;
    dump(root);
    
    if(dfs(root, -1) == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
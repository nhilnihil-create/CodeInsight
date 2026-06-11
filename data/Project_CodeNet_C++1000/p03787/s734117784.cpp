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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    REP(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dump(g);

    bool flag;
    vector<ll> col(n, -1);
    function<void(ll,ll)> dfs = [&](ll v, ll c) {
        col[v] = c;
        for(auto to: g[v]) {
            if(col[to] == c) flag = false;
            if(col[to] == -1) dfs(to, 1-c);
        }
    };
    ll x = 0, y = 0, z = 0;
    REP(i, n) {
        if(g[i].size() == 0) z++;
        else if(col[i] == -1) {
            flag = true;
            dfs(i, 0);
            if(flag) x++;
            else y++;
        }
    }
    dump(x, y, z);
    cout << 2*x*x + 2*x*y + y*y + z*z + 2*z*(n-z) << endl;

    return 0;
}
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
#ifdef DEBUG
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

int main(void) {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    REP(i, n-1) {
        ll a;
        cin >> a;
        a--;
        g[i+1].push_back(a);
        g[a].push_back(i+1);
    }

    auto dfs = [&](auto &&self, ll v, ll p) -> ll {
        vector<ll> ch;
        for(auto to: g[v]) if(to != p) {
            ll t = self(self, to, v);
            ch.push_back(t);
        }
        sort(ALL(ch));
        ll now = 0;
        for(auto i: ch) now = max(now+1, i+1);
        return now;
    };
    cout << dfs(dfs, 0, -1) << endl;

    return 0;
}
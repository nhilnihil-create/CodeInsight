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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m)), b(n, vector<ll>(m));
    REP(i, n) REP(j, m) {
        cin >> a[i][j];
        a[i][j]--;
        b[i][a[i][j]] = j;
    }

    ll ans = n;
    vector<ll> idx(n);
    vector<vector<bool>> del(n, vector<bool>(m));
    REP(t, m) {
        vector<ll> cnt(m);
        REP(i, n) cnt[a[i][idx[i]]]++;
        ll ma = 0, mai = -1;
        REP(i, m) if(ma < cnt[i]) ma = cnt[i], mai = i;
        chmin(ans, ma);

        REP(i, n) {
            del[i][b[i][mai]] = true;
            while(idx[i]<m && del[i][idx[i]]) idx[i]++;
        }
    }
    cout << ans << endl;

    return 0;
}
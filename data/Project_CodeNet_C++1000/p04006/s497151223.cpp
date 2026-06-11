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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    // 魔法をi回
    // j番目はmin(a[j-i+1], …, a[j-1], a[j])かかる
    vector<vector<ll>> mi(n, vector<ll>(n, INF));
    REP(i, n) mi[0][i] = a[i];
    FOR(i, 1, n) {
        REP(j, n) {
            // [j-i, j] = [j-i+1, j] + [j-i]
            mi[i][j] = min(mi[i-1][j], a[(j-i+n)%n]);
        }
    }

    ll ans = INF;
    REP(i, n) {
        ll val = i*k;
        REP(j, n) val += mi[i][j];
        chmin(ans, val);
    }
    cout << ans << endl;

    return 0;
}
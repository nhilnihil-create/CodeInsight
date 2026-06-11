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
    vector<ll> p(n);
    REP(i, n) cin >> p[i], p[i]--;

    vector<ll> a(n), b(n);
    REP(i, n) {
        a[i] = 30000 * i + 1;
        b[i] = 30000 * (n-1-i) + 1;
    }
    REP(i, n) a[p[i]] += i;

    REP(i, n) cout << a[i] << (i==n-1 ? '\n' : ' ');
    REP(i, n) cout << b[i] << (i==n-1 ? '\n' : ' ');

    return 0;
}
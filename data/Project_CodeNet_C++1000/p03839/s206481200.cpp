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

    vector<ll> vl(a), vr(a), rui(a);
    REP(i, n) if(a[i]<0) vl[i] = vr[i] = 0;
    FOR(i, 1, n) {
        vl[i] += vl[i-1];
        rui[i] += rui[i-1];
    }
    for(ll i=n-2; i>=0; --i) vr[i] += vr[i+1];

    ll ans = 0;
    REP(i, n-k+1) {
        // [i, i+k-1] をすべて同じ色にする
        ll val = (i==0?0:vl[i-1]) + (i+k>=n?0:vr[i+k]);
        chmax(ans, val + rui[i+k-1]-(i==0?0:rui[i-1]));
        chmax(ans, val);
    }
    cout << ans << endl;

    return 0;
}
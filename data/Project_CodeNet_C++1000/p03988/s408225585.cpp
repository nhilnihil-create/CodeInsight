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
    vector<ll> a(n), b(n);
    REP(i, n) cin >> a[i], b[a[i]]++;

    ll ma = 0;
    REP(i, n) chmax(ma, a[i]);

    bool flag = true;
    if(ma%2==0) {
        // ma/2未満 → 0個
        REP(i, ma/2) if(b[i] != 0) flag = false;
        // ma/2 → 1個
        if(b[ma/2] != 1) flag = false;
        // ma/2より大きい → 2個以上
        FOR(i, ma/2+1, ma+1) if(b[i] < 2) flag = false;
    } else {
        // ma/2以下 → 0個
        REP(i, ma/2+1) if(b[i] != 0) flag = false;
        // ma/2+1 → 2個
        if(b[ma/2+1] != 2) flag = false;
        // ma以下 → 2個以上
        FOR(i, ma/2+1, ma+1) if(b[i] < 2) flag = false;
    }

    if(flag) cout << "Possible\n";
    else cout << "Impossible\n"; 

    return 0;
}
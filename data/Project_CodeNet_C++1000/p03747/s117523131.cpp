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
#include "../../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

int main(void) {
    ll n, l, t;
    cin >> n >> l >> t;
    vector<ll> x(n), w(n);
    REP(i, n) cin >> x[i] >> w[i];

    vector<ll> pos(n);
    REP(i, n) {
        if(w[i]==1) pos[i] = (x[i]+t)%l;
        else pos[i] = ((x[i]-t)%l+l)%l;
    }
    ll pos0 = pos[0];
    sort(ALL(pos));

    ll cnt = 0;
    REP(i, n) if(w[0] != w[i]) {
        if(w[0]==1 && x[i]-x[0] <= 2*t) {
            // (x[i]-x[0])/2 + kl/2 <= t を満たす最大のk
            ll k = (2*t-x[i]+x[0]) / l;
            cnt += k+1;
        } else if(l-x[i]+x[0] <= 2*t) {
            // (l-x[i]+x[0])/2 + kl/2 <= t
            ll k = (2*t-l+x[i]-x[0]) / l;
            cnt += k+1;
        }
    }
    dump(cnt);

    // 蟻0は位置pos0でゼッケンaになっている
    ll a = w[0]==1 ? cnt%n : ((-cnt)%n+n)%n;

    // 蟻0がans[base]に対応
    ll base = -1;
    REP(i, n) if(pos[i] == pos0) {
        base = i;
        if(w[0] == 2) break;
    }
    vector<ll> ans(n);
    REP(i, n) ans[(i+a)%n] = pos[(base+i)%n];

    dump(pos0, a, base);
    REP(i, n) cout << ans[i] << "\n";

    return 0;
}
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
    ll ai, ao, at, aj, al, as, az;
    cin >> ai >> ao >> at >> aj >> al >> as >> az;

    ll ans = 0;
    {
        ll num = ao;
        num += ai/2*2;
        num += aj/2*2;
        num += al/2*2;
        num += 3 * (ai%2) * (aj%2) * (al%2);
        chmax(ans, num);
    }
    if(ai>0 && aj>0 && al>0) {
        ai--, aj--, al--;
        ll num = 3;
        num += ai/2*2;
        num += aj/2*2;
        num += al/2*2;
        num += ao;
        chmax(ans, num);
    }

    cout << ans << endl;

    return 0;
}
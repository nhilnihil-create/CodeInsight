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
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    b -= a, a = 0;

    if(b < -n*d || n*d < b) {
        cout << "NO" << endl;
        return 0;
    }

    ll lb = -(n-1)*c, ub = c-(n-2)*d;
    REP(i, n-1) {
        if(lb < b && b < ub) {
            cout << "NO" << endl;
            return 0;
        }
        lb += c+d;
        ub += c+d;
    }
    cout << "YES" << endl;

    return 0;
}
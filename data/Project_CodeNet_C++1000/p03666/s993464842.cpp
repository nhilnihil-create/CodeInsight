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

    REP(i, n) {
        // i回足す n-1-i回引く
        // ic-(n-1-i)*d以上 i*d-(n-1-i)*c以下はつくれる
        ll lb = i*c - (n-1-i)*d, ub = i*d - (n-1-i)*c;
        if(lb <= b && b <= ub) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}
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
    ll n, sum = 0;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i], sum += a[i];

    if(sum%(n*(n+1)/2)) {
        cout << "NO" << endl;
        return 0;
    }
    ll num = sum / (n*(n+1)/2);

    vector<ll> b(n);
    REP(i, n) b[i] = a[(i+1)%n] - a[i];
    REP(i, n) {
        if((num-b[i])%n || b[i]>num) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
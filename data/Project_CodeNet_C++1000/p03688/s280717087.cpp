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
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    sort(ALL(a));

    if(a[n-1]-a[0] >= 2) {
        cout << "No" << endl;
    } else if(a[n-1]-a[0] == 1) {
        ll cnt0 = 0, cnt1 = 0;
        REP(i, n) {
            if(a[i]==a[0]) cnt0++;
            else cnt1++;
        }
        if(cnt0 <= a[0] && (a[0]-cnt0+1)*2 <= cnt1) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else if(a[n-1]-a[0] == 0) {
        if(n == a[0]+1 || n >= a[0]*2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
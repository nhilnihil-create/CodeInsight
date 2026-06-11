#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;


int main() {
    ll n, m;
    cin >> n >> m;
    ll x = 0;
    ll y = 0;
    ll a;
    REP(i, n) {
        cin >> a;
        x += (i * a) % MOD - ((n - (i + 1)) * a) % MOD;
        x += MOD;
        x %= MOD;
    }
    REP(i, m) {
        cin >> a;
        y += (i * a) % MOD - ((m - (i + 1)) * a) % MOD;
        y += MOD;
        y %= MOD;
    }
    cout << x * y % MOD << endl;
}

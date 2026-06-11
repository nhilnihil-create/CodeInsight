#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

ll powmod(ll x, ll n) {
    ll res = 1;
    if (n > 0) {
        res = powmod(x, n / 2);
        if (n % 2 == 0) {
            res = (res * res) % MOD;
        } else {
            res = (((res * res) % MOD) * x) % MOD;
        }
    }

    return res;
}

int main() {
    int n, m; cin >> n >> m;
    ll ans = 1;
    if (n == m) {
        while (n > 0) {
            ans *= n;
            ans %= MOD;
            n--;
        }
        ans = powmod(ans, 2);
        ans *= 2;
        ans %= MOD;
    } else if (abs(n - m) == 1) {
        while (n > 0) {
            ans *= n;
            ans %= MOD;
            n--;
        }
        while (m > 0) {
            ans *= m;
            ans %= MOD;
            m--;
        }
    } else {
        ans = 0;
    }

    cout << ans << endl;
    return 0;
}
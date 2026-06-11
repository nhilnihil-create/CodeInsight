#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main() {
    int n, m; cin >> n >> m;
    ll ans = 1;
    int a = n; int b = m;
    while (n > 0) {
        ans *= (ll)n;
        ans %= MOD;
        n--;
    }
    while (m > 0) {
        ans *= (ll)m;
        ans %= MOD;
        m--;
    }

    if (a == b) ans = (ans * 2) % MOD;
    if (abs(a - b) > 1) ans = 0;
    cout << ans << endl;
    return 0;
}
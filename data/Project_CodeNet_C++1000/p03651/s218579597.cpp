#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n, k;
    cin >> n >> k;
    int a[n], g = 0, mx = 0;
    rep(i, n) {
        cin >> a[i];
        g = __gcd(g, a[i]);
        chmax(mx, a[i]);
    }

    cout << (mx >= k && k % g == 0 ? "POSSIBLE" : "IMPOSSIBLE") << endl;

    return 0;
}
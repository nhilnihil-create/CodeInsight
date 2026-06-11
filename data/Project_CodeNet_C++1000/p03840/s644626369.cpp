#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll I, O, T, J, L, S, Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;

    ll ans = (I / 2 + J / 2 + L / 2) * 2;
    if(I && J && L)
        chmax<ll>(ans, ((I - 1) / 2 + (J - 1) / 2 + (L - 1) / 2) * 2 + 3);

    cout << ans + O << endl;

    return 0;
}
#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;

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

ll n, a, b;
V<ll> h;

bool f(const ll &mid) {
    V<ll> x = h;
    ll cnt = 0;
    rep(i, n) {
        x[i] -= b * mid;
        if(x[i] > 0) cnt += (x[i] + a - 1) / a;
    }
    return cnt <= mid;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> a >> b;
    a -= b;
    h.resize(n);
    rep(i, n) cin >> h[i];
    sort(ALL(h), greater<int>());
    ll ng = 0, ok = 1e9;
    while(ng + 1 < ok)
        (f(ok + ng >> 1) ? ok : ng) = ok + ng >> 1;
    cout << ok << endl;

    return 0;
}
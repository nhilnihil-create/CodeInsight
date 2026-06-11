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

ll n, k, sum;
V<ll> a;

bool need(const int &mid) {
    bitset<5005> b(1);
    rep(i, n) if(i != mid) b |= b << a[i];
    FOR(i, max(0LL, k - a[mid]), k) if(b[i]) return true;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;
    a.resize(n);
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    sort(ALL(a));
    ll ok = -1, ng = n;
    while(ok + 1 < ng)
        (need(ng + ok >> 1) ? ng : ok) = ng + ok >> 1;
    cout << ng << endl;

    return 0;
}
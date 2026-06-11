#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
const int mod = 1e9+7;
const int INF = 2e9;
// const ll INF = 1e12;
const int MAX = 1e6;

ll gcd(ll a, ll b) { // aとbの最大公約数（ユークリッドの互除法）
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { // aとbの最小公倍数
    return a / gcd(a, b) * b;
}

ll lcm(vl &a) { // 3つ以上の整数の最小公倍数
    ll r = 1;
    rep(i, (int)a.size()) {
        r = lcm(r, a[i]);
    }
    return r;
}

int main() {
    // input
    int n;
    cin >> n;
    vl t(n);
    rep(i, n) {
        cin >> t[i];
    }
    // solve
    ll ans = lcm(t);
    // output
    cout << ans << endl;
}
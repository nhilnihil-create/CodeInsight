#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <utility>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cstring>

using namespace std;

constexpr long long mod = 1000000007;
constexpr double eps = 0.0000000001;

typedef long long ll;
typedef long long unsigned ull;

pair<ll, ll> extgcd(ll a, ll b) {
    if (b == 0) return make_pair(a, 0);
    else {
        auto t = extgcd(b, a % b);
        return make_pair(t.second, t.first - t.second * (a / b));
    }
}

ll inv_fac_m[200010];
ll fac_m[200010];

ll inv_fac(ll n) {
    if (n == 0) return 1;
    if (!inv_fac_m[n]) inv_fac_m[n] = (inv_fac(n - 1) * (extgcd(n, -mod).first + mod)) % mod;
    return inv_fac_m[n];
}

ll fac(ll n) {
    if (n == 0) return 1;
    if (!fac_m[n]) fac_m[n] = (fac(n - 1) * n) % mod;
    return fac_m[n];
}

ll cmb(ll n, ll k) {
    return (((fac(n) * inv_fac(k)) % mod) * inv_fac(n - k)) % mod;
}

int main() {
    ll h, w, a, b;
    cin >> h >> w >> a >> b;
    ll r = 0;
    for (ll x = b + 1; x <= w; x++) {
        r = (r + (cmb(h - a - 1 + x - 1, x - 1) * cmb(a - 1 + w - x, a - 1))) % mod;
    }
    cout << r << endl;
}
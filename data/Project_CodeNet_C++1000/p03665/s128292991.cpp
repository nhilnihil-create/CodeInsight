
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e15;
static const ll mod = 1e9+7;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

ll mpow(ll x, ll n) {
    ll ans = 1; x %= mod;
    while (n != 0) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n = n >> 1;
    }
    return ans;
}

ll inv_mod(ll a) { return mpow(a, mod - 2); }

class Factorial {
public:
    ll cmb(ll a, ll b) {
        if (a == 0 && b == 0) return 1;
        if (a < b || a < 0 || b < 0) return 0;
        ll c = 1;
        for (int i = a,j=1; i > a - b; i--,j++) {
            c *= i;
            c /= j;
        }
        return c;
    }
};

int main() {
    ll n, p;
    cin >> n >> p;
    vector<ll> as(n);
    rep(i, n) cin >> as[i];
    ll even = 0, odd = 0;
    rep(i, n) {
        if (as[i] % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }
    }
    Factorial f;
    ll eSum = 1;
    rep(i, even) {
        eSum *= 2;
    }
    ll rSum = 0;
    for (int i = 0; i <= odd; i++) {
        if (i % 2 == p) {
            rSum += f.cmb(odd, i);
        }
    }
    cout << eSum * rSum << endl;
    return 0;
}

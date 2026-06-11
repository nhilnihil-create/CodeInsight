#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<ll,ll> P;

#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

constexpr ll mod = 1e9 + 7;

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
private:
    vector<ll> fac;
    vector<ll> ifac;
public:

    Factorial(ll N) {
        fac.push_back(1);
        for (int i = 0; i < N; i++) fac.push_back(fac[i] * (i + 1) % mod);
        ifac.resize(N + 1);
        ifac[N] = inv_mod(fac[N]);
        for (int i = 0; i < N; i++) ifac[N - 1 - i] = (ifac[N - i] * (N - i)) % mod;
    }

    ll fact(ll a) { return fac[a]; }
    ll ifact(ll a) { return ifac[a]; }

    ll cmb(ll a, ll b) {
        if (a == 0 && b == 0) return 1;
        if (a < b || a < 0 || b < 0) return 0;
        ll tmp = ifact(a - b) * ifact(b) % mod;
        return tmp * fac[a] % mod;
    }
    ll per(ll a, ll b) {
        if (a == 0 && b == 0) return 1;
        if (a < b || a < 0 || b < 0) return 0;
        return fac[a] * ifac[a - b] % mod;
    }
};


int main() {
	int n, m;
    cin >> n >> m;
    if (abs(n - m) > 1) {
        cout << 0 << endl;
    }
    else if (abs(n - m) == 0) {
        Factorial f(n + m);
        auto a = f.per(n, n) * f.per(m, m) * 2;
        cout << a % mod << endl;
    }
    else {
        Factorial f(n + m);
        auto a = f.per(n, n)* f.per(m, m);
        cout << a % mod << endl;
    }
	return 0;
}

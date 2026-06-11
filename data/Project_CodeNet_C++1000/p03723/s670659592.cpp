#include "bits/stdc++.h"
#define rep(i, j) for (int i = 0; i < j; i++)
using namespace std;
using ll = long long;

/*struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) :x((x% mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream & is, const mint & a) { return is >> a.x; }
ostream& operator<<(ostream & os, const mint & a) { return os << a.x; }*/

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;

    if (a == b && b == c) {
        if (a % 2 == 0)
            cout << -1 << endl;
        else
            cout << 0 << endl;

        return 0;
    }

    while (1) {
        if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1)
            break;
        ll n_a, n_b, n_c;
        n_a = b / 2 + c / 2;
        n_b = a / 2 + c / 2;
        n_c = a / 2 + b / 2;
        ans++;
        a = n_a, b = n_b, c = n_c;
    }

    cout << ans << endl;
    return 0;
}

#include "bits/stdc++.h"
#define rep(i, j) for (int i = 0; i < j; i++)
using namespace std;
using ll = long long;

int gcd(int x, int y);

const int INF = 1001001001;

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
    string rode;
    cin >> rode;
    int n = 0, s = 0;
    int w = 0, e = 0;

    rep(i, rode.size()) {
        switch (rode[i]) {
        case 'N':
            n++;
            break;
        case 'S':
            s++;
            break;
        case 'W':
            w++;
            break;
        case 'E':
            e++;
            break;
        }
    }
    if ((n == 0 && s != 0) || (n != 0 && s == 0)) {
        cout << "No" << endl;
        return 0;
    }
    if ((e == 0 && w != 0) || (e != 0 && w == 0)) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}

/*���C�u�����ő����*/
//���[�O���b�h�̌ݏ��@
int gcd(int x, int y) {
    int num[3];
    num[0] = (x > y) ? x : y;
    num[1] = (x <= y) ? x : y;
    num[2] = num[0] % num[1];

    while (num[2]) {
        num[0] = num[1];
        num[1] = num[2];
        num[2] = num[0] % num[1];
    }

    return num[1];
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
#define REP(i, n)  for(int i = 0; i < n; ++i)
#define FOR(i, t, n)  for(ll i = t; i <= (ll)n; ++i)
struct edge {
    int from, to;
    ll cost;
};


class Eratosthenes {
public:
    vector<bool> prime;

    Eratosthenes(int size) {
        prime.resize(size + 1, 1);
        prime[0] = 0;
        prime[1] = 0;
        FOR(i, 2, size) {
            if (prime[i]) {
                for (int j = 2 * i; j <= size; j += i) {
                    prime[j] = 0;
                }
            }
        }
    }

};


class Combination {
    vector<ll> fac; //n!(mod M)
    vector<ll> ifac; //k!^{M-2} (mod M)
public:
    Combination(ll size) {
        fac.resize(size);
        ifac.resize(size);
        fac[0] = 1;
        ifac[0] = 1;
        for (ll i = 0; i < size; i++) {
            fac[i + 1] = fac[i] * (i + 1) % MOD;
            ifac[i + 1] = ifac[i] * mpow(i + 1, MOD - 2) % MOD;
        }
    }

    ll mpow(ll x, ll n) {
        ll ans = 1;
        while (n != 0) {
            if (n & 1) ans = ans * x % MOD;
            x = x * x % MOD;
            n = n >> 1;
        }
        return ans;
    }

    ll comb(ll a, ll b) {
        if (a == 0 && b == 0)return 1;
        if (a < b || a < 0)return 0;
        ll tmp = ifac[a - b] * ifac[b] % MOD;
        return tmp * fac[a] % MOD;
    }
};


ll GCD(ll a, ll b) {
    if (b == 0)return a;
    return GCD(b, a % b);
}

int H, W;
int a[30], num[10];

int main() {
    cin >> H >> W;
    bool ho = H % 2 == 1, wo = W % 2 == 1;
    REP(i, H) {
        string s;
        cin >> s;
        REP(j, W) a[s[j] - 'a']++;
    }
    int m = min(2, H) * min(W, 2);
    REP(c, 26) {
        while (a[c] > 0) {
            if (a[c] >= m)a[c] -= m, num[m]++;
            else if (a[c] >= 2) {
                a[c] -= 2, num[2]++;
            } else num[1]++, a[c]--;
        }
    }
    int v = (H / 2) * (W / 2);
    int x = (H / 2) * wo + (W / 2) * ho;
    if (ho && wo) {
        if (num[1] == 1) {
            if ((num[2] == x && num[4] == v) || (x == 2 * (num[4] - v))) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    } else {
        if (num[1] == 0) {
            if ((num[2] == x && num[4] == v) || (x == 2 * (num[4] - v))) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}


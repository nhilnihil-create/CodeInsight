#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
const int mod = 1e9+7;

long long power(int m, int n) { // m^n
    if (n == 0) return 1;
    if (n % 2 == 1) return m * power(m, n - 1) % mod;
    long long r = power(m, n / 2);
    return r * r % mod;
}
long long inv(int a, int b) { // a/b(mod)
    return a * power(b, mod-2) % mod;
}
struct combination {
    int MAX;
    vector<long long> fact;
    combination(int _n) {
        MAX = _n;
        fact.resize(MAX + 1, 0); // 階乗
        for (int i = 0; i <= MAX; i++) {
            if (i == 0) fact[i] = 1;
            else fact[i] = i * fact[i-1] % mod;
        }
    }
    long long perm(int n, int r) { // nPr
        if (n < r) return 0;
        return inv(fact[n], fact[n-r]);
    }
    long long comb(int n, int r) { // nCr
        if (n < r) return 0;
        return inv(perm(n, r), fact[r]);
    }
    long long pie(int n, int k) { // 包除原理
        long long s = 0;
        for (int i = 0; i < k; i++) {
            s += power(-1, i) * comb(k, i) * power(k-i, n);
            s %= mod;
            if (s < 0) s += mod;
        }
        return s;
    }
};

int main() {
    combination c((int)1e5);
    int n, m;
    cin >> n >> m;
    if (abs(n - m) > 1) {
        cout << 0 << endl;
        return 0;
    }
    ll r = (c.fact[n] * c.fact[m]) % mod;
    if (n == m) {
        r *= 2;
        r %= mod;
    }
    cout << r << endl;
}
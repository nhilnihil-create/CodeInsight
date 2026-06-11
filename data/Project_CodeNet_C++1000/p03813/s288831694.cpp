#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

long long mod = 1000000007;

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return (t * t) % mod;
    } else {
        return (modpow(m, n - 1) * m) % mod;
    }
}
int power(long long x, long long y, long long p) {
    long long res = 1;  // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) res = (res * x) % p;

        // y must be even now
        y = y >> 1;  // y = y/2
        x = (x * x) % p;
    }
    return res;
}

long long modInverse(long long n, long long p) { return power(n, p - 2, p); }

long long nCrModPFermat(long long n, long long r, long long p) {
    if (r == 0) return 1;
    long long fac[n + 1];
    fac[0] = 1;
    for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)

signed main() {
    long long ans = 0;
    int n;
    cin >> n;
    if (n < 1200){
        cout << "ABC" << endl;
    }else{
        cout << "ARC" << endl;
    }
}
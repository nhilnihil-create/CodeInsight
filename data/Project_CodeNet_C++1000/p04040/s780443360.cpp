#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const long long int MOD = 1000000007;

int fact[N], ifact[N];
int v[N];

void mult(int &a, int b) {
    long long p = 1LL * a * b;
    if (p >= MOD) p %= MOD;
    a = (int)p;
}

int fexp(int base, int exp) {
    if (base >= MOD) base %= MOD;
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) mult(result, base);
        exp >>= 1;
        mult(base, base);
    }
    return result;
}

void precalc() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1];
        mult(fact[i], i);
    }

    ifact[N - 1] = fexp(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i) {
        ifact[i] = ifact[i + 1];
        mult(ifact[i], i + 1);
    }
}

inline int nCr(int n, int r) {
    if (n < r) return 0;
    if (n == r) return 1;

    int res = fact[n];
    mult(res, ifact[r]);
    mult(res, ifact[n - r]);

    return res;
}

int main() {
    precalc();

    int h, w, a, b; 
    scanf("%d%d%d%d", &h, &w, &a, &b);
    
    for (int j = b; j < w; j++) {
        v[j - b] = nCr(h - a - 1 + j, j); 
    }

    int ans = 0;
    int n = a - 1;
    for (int j = w - b - 1; j >= 0; j--) {
        int add = nCr(n, a - 1);
        mult(add, v[j]);

        ans += add;
        if (ans >= MOD) ans -= MOD;

        ++n;
    }

    cout << ans;
    return 0;
}
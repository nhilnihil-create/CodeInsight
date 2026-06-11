#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

long long mod = 1000000007;
#define REP(i, n) for (long long i = 0; i < (n); i++)

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t % mod;
    } else {
        return modpow(m, n - 1) * m % mod;
    }
}

long long moddiv(long long a, long long b) { return (a * modpow(b, mod - 2)) % mod; }

long long nCkmod(long long n, long long k) {
    long long denomi = 1;
    REP(i, n) {
        denomi *= (i + 1);
        denomi %= mod;
    }
    long long numera = 1;
    for (int i = n - k; i > 0; i--) {
        numera *= i;
        numera %= mod;
    }
    REP(i, k) {
        numera *= (i + 1);
        numera %= mod;
    }
    return moddiv(denomi, numera);
}

void print_binary(long long a) {
    for (int i = 31; i >= 0; i--) {
        cout << (a >> i & 1);
    }
    cout << endl;
}

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}

vector<int> h, memo;

// int dp(int n) {
//     if (memo[n] != -1) {
//         return memo[n];
//     }
//     if (n == 0) {
//         return 0;
//     }
//     if (n == 1) {
//         return abs(h[1] - h[0]);
//     }
//     memo[n] = min(dp(n - 1) + abs(h[n] - h[n - 1]), dp(n - 2) + abs(h[n] - h[n - 2]));
//     return min(dp(n - 1) + abs(h[n] - h[n - 1]), dp(n - 2) + abs(h[n] - h[n - 2]));
// }
signed main() {
    long long a, b, c, d, n;
    long long cost = 0;
    cin >> a >> b >> c >> d >> n;
    long long l2, l1;
    l2 = min({a * 8, b * 4, c * 2, d});
    l1 = min({a * 4, b * 2, c});
    // cout << l2 << " " << l1 << endl;
    cost += (n / 2) * l2;
    n = n % 2;
    // cout << cost << endl;
    if (n == 0) {
        cout << cost << endl;
        return 0;
    }
    cost += l1;
    cout << cost << endl;
}
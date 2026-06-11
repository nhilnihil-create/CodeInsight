#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const long long MOD = 1000000007;

int main() {
    long long n, d;
    cin >> n;
    pair<long long, long long> a[n + 1];
    for (long long i = 0; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n + 1);
    for (long long i = 1; i <= n; i++) {
        if (a[i].first == a[i - 1].first) {
            d = a[i].second - a[i - 1].second;
        }
    }
    long long factorial[n + 2], ifactorial[n + 2], inv[n + 2];
    inv[1] = 1;
    factorial[0] = 1;
    factorial[1] = 1;
    ifactorial[0] = 1;
    ifactorial[1] = 1;
    for (long long i = 2; i <= n + 1; i++) {
        inv[i] = (-MOD / i + MOD) * inv[MOD % i] % MOD;
        factorial[i] = factorial[i - 1] * i % MOD;
        ifactorial[i] = ifactorial[i - 1] * inv[i] % MOD;
    }
    function<long long(long long, long long)> binomial = [&](long long n, long long k) {
        return factorial[n] * ifactorial[k] % MOD * ifactorial[n - k] % MOD;
    };
    for (long long k = 1; k <= n + 1; k++) {
        long long result = binomial(n + 1, k);
        if (n - d >= k - 1) {
            result = result - binomial(n - d, k - 1);
            if (result < 0) {
                result += MOD;
            }
        }
        cout << result << '\n';
    }
    return 0;
}

#include <iostream>
#include <functional>
using namespace std;

const long long MOD = 1000000007;

int main() {
    long long h, w, a, b, result = 0;
    cin >> h >> w >> a >> b;
    long long factorial[w + h], ifactorial[w + h], inv[w + h];
    factorial[0] = 1;
    ifactorial[0] = 1;
    inv[1] = 1;
    factorial[1] = 1;
    ifactorial[1] = 1;
    for (long long i = 2; i < w + h; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
        inv[i] = (-MOD / i + MOD) * inv[MOD % i] % MOD;
        ifactorial[i] = ifactorial[i - 1] * inv[i] % MOD;
    }
    function<long long(long long, long long)> binomial = [&](long long n, long long k) {
        return factorial[n] * ifactorial[k] % MOD * ifactorial[n - k] % MOD;
    };
    for (long long i = 0; i < h - a; i++) {
        result = (result + binomial(b + i - 1, i) * binomial(w - b + h - i - 2, h - i - 1)) % MOD;
    }
    cout << result;
    return 0;
}

#include "bits/stdc++.h"

using namespace std;

const long long MOD = 1000000007;

long long fractorial_mod(long long n) {
    long long ret = 1;
    for (long long i = 2; i <= n; ++i) {
        ret *= i;
        ret %= MOD;
    }
    return ret;
}

void Main() {
    long long N, M;
    cin >> N >> M;

    if (abs(N - M) > 1) {
        cout << 0 << endl;
        return;
    }

    long long ans = 0LL;
    if (N == M) {
        ans += fractorial_mod(N) * fractorial_mod(M);
        ans %= MOD;
        ans *= 2;
        ans %= MOD;
    }
    else {
        ans += fractorial_mod(N) * fractorial_mod(M);
        ans %= MOD;
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

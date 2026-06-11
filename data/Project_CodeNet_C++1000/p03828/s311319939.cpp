#include "bits/stdc++.h"

using namespace std;

long long MOD = 1000000007LL;

void Main() {
    long long N;
    cin >> N;

    map<long long, long long> factors;
    for (long long i = 2; i <= N; ++i) {
        long long k = i;
        for (long long j = 2; j * j <= i; ++j) {
            long long e = 0;
            while (k % j == 0) {
                k /= j;
                ++e;
            }
            if (e > 0) {
                if (factors.count(j) == 0) {
                    factors.insert(make_pair(j, 0LL));
                }
                factors[j] += e;
            }
        }
        if (k != 1) {
            if (factors.count(k) == 0) {
                factors.insert(make_pair(k, 0LL));
            }
            factors[k] += 1;
        }
    }
    long long ans = 1;
    for (auto e : factors) {
        ans *= (e.second + 1);
        ans %= MOD;
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

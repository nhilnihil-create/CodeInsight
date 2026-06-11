#include "bits/stdc++.h"

using namespace std;

const long long MOD = 1000000007;

map<long long, long long> primeFactorization(long long n) {
    map<long long, long long> ret;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.insert(make_pair(i, 0));
        }
        while (n % i == 0) {
            n /= i;
            ret[i] += 1;
        }
    }
    if (n != 1) {
        ret.insert(make_pair(n, 1));
    }
    return ret;
}

void Main() {
    long long N;
    cin >> N;

    map<long long, long long> factors;
    for (long long n = 2; n <= N; ++n) {
        map<long long, long long> fn = primeFactorization(n);
        for (auto e : fn) {
            if (factors.count(e.first) == 0) {
                factors.insert(make_pair(e.first, 0));
            }
            factors[e.first] += e.second;
        }
    }

    long long ans = 1LL;
    for (auto e : factors) {
        ans *= (e.second + 1LL);
        ans %= MOD;
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

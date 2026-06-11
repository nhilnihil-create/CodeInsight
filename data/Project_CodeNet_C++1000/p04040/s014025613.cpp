//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <complex>
#include <regex>

using namespace std;

#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}

constexpr long long MOD = 1e9 + 7;
long long fac[400010];
long long inv[400010];

long long pow_mod(long long n, long long p) {
    long long ret = 1;
    while (p > 0) {
        if (p & 1) ret = (ret * n) % MOD;
        n = (n * n) % MOD;
        p >>= 1;
    }
    return ret;
}

void prepare() {
    fac[0] = fac[1] = 1LL;
    inv[0] = inv[1] = 1LL;
    for (long long i = 2; i <= 400000; i++) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= MOD;
        inv[i] = pow_mod(fac[i], MOD - 2LL);
    }
}

long long ncr_mod(long long n, long long r) {
    return fac[n] * inv[n - r] % MOD * inv[r] % MOD;
}

int main() {

    long long H, W, A, B;
    cin >> H >> W >> A >> B;

    prepare();

    long long ans = 0;

    for (long long w = B; w < W; w++) {
        long long w1 = w;
        long long h1 = (H - A - 1);
        long long sum1 = ncr_mod(w1 + h1, w1);
        long long w2 = W - w1 - 1;
        long long h2 = A - 1;
        long long sum2 = ncr_mod(w2 + h2, w2);
        ans += (sum1 * sum2) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}




























































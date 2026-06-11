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

constexpr long long mod = 1e9 + 7;

long long pow_mod(long long n, long long p) {
    long long ret = 1;
    while (p > 0) {
        if (p & 1) ret = (ret * n) % mod;
        n = (n * n) % mod;
        p >>= 1;
    }
    return ret;
}

void prepro(vector<long long> &fin, vector<long long> &inv) {
    fin[0] = fin[1] = 1;
    inv[0] = inv[1] = 1;
    for (long long i = 2; i <= 201000; i++) {
        fin[i] = (fin[i - 1] * i) % mod;
        inv[i] = pow_mod(fin[i], mod - 2);
    }
}

long long ncr_mod_prepro(vector<long long> &fin, vector<long long> &inv, long long n, long long r) {
    return fin[n] * inv[r] % mod * inv[n - r] % mod;
}

int main() {

    vector<long long> fin(202000), inv(202000);
    prepro(fin, inv);

    long long H, W, A, B;
    cin >> H >> W >> A >> B;

    long long ans = 0;
    for (long long w = B; w < W; w++) {
        long long left_w = w;
        long long right_w = W - w - 1;
        long long left_h = H - A - 1;
        long long right_h = A - 1;
        ans += (ncr_mod_prepro(fin, inv, left_w + left_h, left_w) * ncr_mod_prepro(fin, inv, right_h + right_w, right_w));
        ans %= mod;
    }

    cout << ans << endl;
}
































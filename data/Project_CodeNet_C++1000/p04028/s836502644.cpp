#include <iostream>
using namespace std;

using int64 = long long;

const int64 mod = 1e9 + 7;

int64 pow_mod(int64 a, int64 x) {
    if (x == 0) return 1;
    else if (x % 2 == 0) {
        int64 b = pow_mod(a, x / 2);
        return (b * b) % mod;
    } else {
        return (a * pow_mod(a, x - 1)) % mod;
    }
}

int main() {
    int N;
    string s;
    cin >> N;
    cin >> s;

    static int64 dp[5010][5010];
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j - 1 >= 0) (dp[i + 1][j - 1] += dp[i][j]) %= mod;
            else (dp[i + 1][j] += dp[i][j]) %= mod;
            (dp[i + 1][j + 1] += 2 * dp[i][j]) %= mod;
        }
    }

    int64 inv = pow_mod(2, mod - 2);
    cout << (dp[N][s.size()] * pow_mod(inv, s.size())) % mod << endl;

    return 0;
}
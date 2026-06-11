#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    ll N, M, result = 1, MOD = 1000000000 + 7;
    cin >> N >> M;
    REP(i, N) {
        result = result * (i + 1) % MOD;
    }
    REP(i, M) {
        result = result * (i + 1) % MOD;
    }
    if (abs(N - M) > 1) {
        cout << 0 << endl;
    } else {
        if (N == M) {
            result = result * 2 % MOD;
        }
        cout << result << endl;
    }
}

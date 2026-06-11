// https://atcoder.jp/contests/abc052/tasks/arc067_a
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
const int MOD = 1e9 + 7;
const int SZ = 1e3;

// constexprな素数列挙(エラトステネスの篩)
// https://259-momone.hatenablog.com/entry/2018/05/06/015026
template <int N> struct Prime {
    bool b[N + 1]; // trueなら素数
    constexpr Prime() : b() {
        fill_n(b, N + 1, true);
        b[0] = b[1] = false;
        for (int_fast64_t i = 2; i <= N; ++i) {
            if (b[i]) {
                for (int_fast64_t j = i * i; j <= N; j += i) {
                    b[j] = false;
                }
            }
        }
    }
};
Prime<SZ> prime;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll ans = 1;
    FOR(i, 2, n + 1) {
        // 素数の場合
        if (prime.b[i]) {
            // n!の中で素因数iは何乗か？
            ll tot = 0;
            for (int j = i; j <= n; j *= i) { // 2,4,8...
                tot += n / j;                 // 12/2 + 12/4 + 12/8
            }
            //約数の個数*(tot+1)%modで更新
            ans = (ans * (tot + 1)) % MOD;
        }
    }
    cout << ans << endl;

    return 0;
}

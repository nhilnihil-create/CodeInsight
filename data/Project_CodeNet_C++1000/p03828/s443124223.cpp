// https://atcoder.jp/contests/abc052/tasks/arc067_a
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
const int MOD = 1e9 + 7;

// 素因数分解 (第2引数は参照渡しして戻り値として利用)
void enumpr(int n, unordered_map<int, int> &V) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            V[i]++;
            n /= i;
        }
    }
    if (n > 1)
        V[n]++;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    unordered_map<int, int> V;
    // 素因数分解を2〜Nまで行う
    for (int i = 2; i <= N; i++) {
        enumpr(i, V);
    }
    int ans = 1;
    for (auto &x : V) {
        // 因数(x.first)が0個〜x.second個までの(x.second + 1)通り
        ans *= (x.second + 1);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}

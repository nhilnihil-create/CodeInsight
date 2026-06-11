#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr ll MOD = 1e9 + 7;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
ll dp[100010][2][2];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<char> c(n - 1);
    int t = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= t;
        if (i < n - 1) {
            cin >> c[i];
            if (c[i] == '-') {
                t = -1;
            } else {
                t = 1;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -LINF;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        chmax(dp[i + 1][0][0], dp[i][0][0] + a[i]);
        chmax(dp[i + 1][0][1], dp[i][0][1] + a[i]);
        chmax(dp[i + 1][1][1], dp[i][1][1] - a[i]);
        if (i > 0 && c[i - 1] == '-') {
            chmax(dp[i + 1][1][1], dp[i][0][0] + a[i]);
            chmax(dp[i + 1][1][1], dp[i][0][1] + a[i]);
            chmax(dp[i + 1][0][1], dp[i][1][1] - a[i]);
        } else if (i > 0) {
            chmax(dp[i + 1][1][1], dp[i][0][1] + a[i]);
        }
    }
    cout << max(dp[n][0][1], dp[n][0][0]) << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int dp[50][500][500];

int main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(500, vector<int>(500, 1e9)));
    dp[0][0][0] = 0;
    rep(i, n) rep(sss, 500) rep(ttt, 500) {
        dp[i + 1][sss][ttt] = min(dp[i + 1][sss][ttt], dp[i][sss][ttt]);
        if (sss + a[i] < 500 && ttt + b[i] < 500) {
            dp[i + 1][sss + a[i]][ttt + b[i]] = min(dp[i + 1][sss + a[i]][ttt + b[i]], dp[i][sss][ttt] + c[i]);
        }
    }
    int ans = 1e9;
    int i = 1;
    while (ma * i < 500 && mb * i < 500) {
        ans = min(ans, dp[n][ma * i][mb * i]);
        i++;
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n);
    rep(i, n)cin >> a[i] >> b[i] >> c[i];
    int INF = 1001001;
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(401, vector<int>(401, INF)));
    rep(i, n + 1)dp[i][0][0] = 0;
    rep(i, n)rep(j, 401)rep(k, 401){
        if(j >= a[i] && k >= b[i]){
            dp[i+1][j][k] = min(dp[i][j][k], dp[i][j-a[i]][k-b[i]] + c[i]);
        }else dp[i+1][j][k] = dp[i][j][k];
    }
    int ans = INF;
    rep(i, 401)rep(j, 401){
        if(i * j == 0)continue;
        if(j * ma == i * mb)ans = min(ans, dp[n][i][j]);
    }
    cout << ((ans == INF) ? -1 : ans) << endl;
}
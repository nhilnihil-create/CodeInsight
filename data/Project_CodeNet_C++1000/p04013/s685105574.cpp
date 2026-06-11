#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    rep(i, n)cin >> x[i];
    rep(i, n)x[i] -= a;
    vector<vector<ll>> dp(n+1, vector<ll>(5001, 0));
    dp[0][2500] = 1;
    rep(i, n){
        rep(j, 5001){
            dp[i+1][j] = dp[i][j] + dp[i][j - x[i]];
        }
    }
    cout << dp[n][2500] - 1 << endl;
}
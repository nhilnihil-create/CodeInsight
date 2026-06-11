#include <bits/stdc++.h>
#define mod 1000000007ll
using namespace std;
typedef long long ll;

ll n, p, a[60], ans, dp[60][2];
// dp[i][j] iは何袋までか jは2で割ったあまり
int main() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i + 1][(j + a[i]) % 2] += dp[i][j];
            dp[i + 1][j] += dp[i][j];
        }
    }
    cout << dp[n][p] << endl;
}
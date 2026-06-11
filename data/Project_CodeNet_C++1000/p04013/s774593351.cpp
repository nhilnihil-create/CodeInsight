#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

long long x[60], dp[60][60][2600];

int main() {
    int N, A;
    cin >> N >> A;
    rep(i, N) cin >> x[i];
    
    dp[0][0][0] = 1;
    rep(i, N) rep(j, 50) rep(k, 2550) {
        dp[i + 1][j][k] += dp[i][j][k];
        dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
    }
    long long ans = 0;
    REP(i, N + 1) {
        ans += dp[N][i][A * i];
    }
    cout << ans << endl;
    return 0;
}

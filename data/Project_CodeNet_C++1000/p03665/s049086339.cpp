#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    vector<vector<long long>> dp(N + 1, vector<long long>(2, 0));
    dp[0][0] = 1;
    rep(i, N) {
        dp[i + 1][0] += dp[i][0];
        dp[i + 1][1] += dp[i][1];
        if (A[i] & 1) {
            dp[i + 1][0] += dp[i][1];
            dp[i + 1][1] += dp[i][0];
        } else {
            dp[i + 1][0] += dp[i][0];
            dp[i + 1][1] += dp[i][1];
        }
    }
    cout << dp[N][P] << endl;
    return 0;
}

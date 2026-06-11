#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i=0; i<(n); ++i)
const int MAX_S = 1e4 + 10;

int main() {
    int n; cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];
    vector<vector<int>> dp(n+1, vector<int>(MAX_S, 0));
    dp[0][0] = 1;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<MAX_S; ++j) {
            dp[i+1][j] |= dp[i][j];
            if (j >= s[i]) {
                dp[i+1][j] |= dp[i][j - s[i]];
            }
        }
    }
    int ans = 0;
    rep(i, MAX_S) {
        if (i%10 == 0) continue;
        if (dp[n][i]) ans = i;
    }
    cout << ans << endl;
}
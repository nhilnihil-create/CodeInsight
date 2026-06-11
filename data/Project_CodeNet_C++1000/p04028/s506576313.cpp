#include <cstring>
#include <iostream>
#define M 1000000007
using namespace std;
int main() {
    int n; cin >> n;
    string s; cin >> s;
    long long dp[2][n+2];
    memset(dp, 0, sizeof(dp));
    int cur = 0, prev = 1;
    dp[prev][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[cur][j] = 2 * dp[prev][j] + 2 * dp[prev][j+1];
            if (j > 0) dp[cur][j] += dp[prev][j-1] - 2 * dp[prev][j];
            else dp[cur][j] += dp[prev][j] - 2 * dp[prev][j+1];
            dp[cur][j] = (dp[cur][j] % M + M) % M;
        }
        swap(cur, prev);
    }
    cout << ((dp[prev][s.size()] - 2 * dp[prev][s.size()+1]) % M + M) % M << endl;
}

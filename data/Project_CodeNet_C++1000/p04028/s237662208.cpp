#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;
const int N = 5010;

ll dp[N][N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    string s;
    cin >> k >> s;
    int n = s.length();
    dp[0][0] = 1;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= k + 1; ++j) {
            if (j) {
                dp[i + 1][j] = (dp[i][j - 1] + 2 * dp[i][j + 1]) % M;
            } else {
                dp[i + 1][j] = (dp[i][j] + 2 * dp[i][j + 1]) % M;
            }
        }
    }
    cout << dp[k][n];
    return 0;
}
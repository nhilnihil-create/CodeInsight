#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, A;
    cin >> N >> A;
    int x[N];
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        x[i] -= A;
    }
    int l = 2 * 50 * 50 + 1;
    int m = 50 * 50;
    ll dp[N + 1][l]{};
    dp[0][m] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0;j < l; j++) {
            dp[i + 1][j] = dp[i][j];
        }
        for (int j = 0; j < l; j++) {
            if (0 <= j - x[i] && j - x[i] < l) {
                dp[i + 1][j - x[i]] += dp[i][j];
            }
        }
    }
    cout << dp[N][m] - 1<< "\n";
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

// dp[i][j][k]: i番目までのカードをj枚用いて合計がkになるような選び方の数
long long dp[51][51][2501] = {0};

int main()
{
    int N, A;
    cin >> N >> A;

    long long max_sum = N * A;

    int x[51];
    for (int i = 1; i <= N; i++) {
        cin >> x[i];
    }

    // i = 1
    dp[1][0][0] = 1;
    dp[1][1][x[1]] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= max_sum; k++) {
                if (k - x[i] < 0) {
                    // カードを加えない場合のみ
                    dp[i][j][k] = dp[i - 1][j][k];
                } else {
                    // カードを加えない場合 + 合計が k - x[i] からカードを加える場合
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - x[i]];
                }
            }
        }
    }
/*
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            ans += dp[i][j][j * A];
            cout << i << "枚目までから" << j << "枚を用いて合計が" << j * A << " = " << dp[i][j][j * A]  << endl;
        }
    }
*/
    long long ans = 0;
    for (int j = 1; j <= N; j++) {
        ans += dp[N][j][j * A];
    }

    cout << ans << endl;

    return 0;
}
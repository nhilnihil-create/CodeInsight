#include<iostream>

using namespace std;

static const int MAX_N = 40;
static const int MAX_V = 10;

static const int INF = 1000000;

int N;
int Ma;
int Mb;
int a[MAX_N + 1];
int b[MAX_N + 1];
int c[MAX_N + 1];

int dp[MAX_N + 1][MAX_N * MAX_V + 1][MAX_N * MAX_V + 1];

int main() {
    cin >> N;
    cin >> Ma >> Mb;

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }

    //////

    for (int i = 0; i <= MAX_N; i++) {
        for (int j = 0; j <= MAX_N * MAX_V; j++) {
            for (int k = 0; k <= MAX_N * MAX_V; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    //////

    dp[0][0][0] = 0;
    for (int i = 1; i <= MAX_N; i++) {
        for (int j = 0; j <= MAX_N * MAX_V; j++) {
            for (int k = 0; k <= MAX_N * MAX_V; k++) {
                if (dp[i - 1][j][k] == INF) continue;

                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                dp[i][j + a[i]][k + b[i]] = min(dp[i - 1][j][k] + c[i], dp[i][j + a[i]][k + b[i]]);
            }
        }
    }

    int ans = INF;
    for (int j = 1; j <= MAX_N * MAX_V; j++) {
        for (int k = 1; k <= MAX_N * MAX_V; k++) {
            if (j * Mb == k * Ma) ans = min(ans, dp[N][j][k]);
        }
    }

    if (ans == INF) ans = -1;

    cout << ans << endl;

    return 0;
}

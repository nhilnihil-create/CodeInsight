#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 5, M = 5, inf = 1e15;
int dp[N][M], a[N];
char op[N];

int Sign(int x) {
    if (x % 2) return -1;
    return 1;
}

int32_t main() {
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) dp[i][j] = -inf;
    int n; cin >> n >> a[0];
    for (int i = 1; i < n; i++) cin >> op[i] >> a[i];
    dp[0][0] = a[0];
    for (int i = 1; i < n; i++) for (int j = M - 1; j >= 0; j--) {
        if (op[i] == '+') dp[i][j] = dp[i - 1][j] + a[i] * Sign(j);
        else if (j) dp[i][j] = dp[i - 1][j - 1] + a[i] * Sign(j);
        if (j + 1 < M) dp[i][j] = max(dp[i][j], dp[i][j + 1]);
    }
    cout << dp[n-1][0] << "\n";
}

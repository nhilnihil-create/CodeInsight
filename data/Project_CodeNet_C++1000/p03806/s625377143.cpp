#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

const int maxgram = 400;

int main() {
    int N, ma, mb; cin >> N >> ma >> mb;
    vector<int> A(N), B(N), C(N);
    REP(i, 0, N) cin >> A[i] >> B[i] >> C[i];

    vector<vector<int>> dp(maxgram + 1, vector<int>(maxgram + 1, 1 << 30));
    dp[0][0] = 0;
    REP(i, 0, N) {
        for (int j = maxgram; j >= 0; j--) {
            if (j + A[i] > maxgram) continue;
            for (int k = maxgram; k >= 0; k--) {
                if (k + B[i] > maxgram) continue;
                dp[j + A[i]][k + B[i]] = min(dp[j + A[i]][k + B[i]], dp[j][k] + C[i]);
            }
        }
    }

    int ans = 1 << 30;
    REP(i, 1, maxgram + 1) {
        REP(j, 1, maxgram + 1) {
            if (i * mb != j * ma) continue;
            ans = min(ans, dp[i][j]);
        }
    }
    if (ans < (1 << 30)) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 50 + 5, LN = 17, MOD = 1e9 + 7, INF = 0x3f3f3f3f, BSZ = 320;
int N, A, a[MN];
ll dp[MN][MN][2505];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> A;
    int sum = 0;
    for (int i = 1; i <= N; i++) cin >> a[i], sum += a[i];
    dp[0][0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= sum; k++) {
                dp[i][j][k] += dp[i - 1][j][k];
                if (j > 0 && k >= a[i]) {
                    dp[i][j][k] += dp[i - 1][j - 1][k - a[i]];
                }
            }
        }
    }
    ll ret = 0;
    for (int i = 1; i <= N; i++) ret += dp[N][i][i * A];
    cout << ret << '\n';
    return 0;
}

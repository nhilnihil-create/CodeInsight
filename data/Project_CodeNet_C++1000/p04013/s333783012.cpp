#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1000000007;
const int INF = 1000000000;
const double EPS = 1e-9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, A;
    cin >> N >> A;
    vector<int> x(N);
    int K = A;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        K = max(K, x[i]);
    }
    K = A;
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(N + 1, vector<ll>(K * N + 1, 0)));
    dp[0][0][0] = 1;
            for (int s = 0; s < K * N + 1; ++s) {
        for (int k = 0; k < N + 1; ++k) {
    for (int j = 0; j < N + 1; ++j) {
                if (x[j - 1] > s && j >= 1) {
                    dp[j][k][s] = dp[j - 1][k][s];
                }
                if (x[j - 1] <= s && j >= 1 && k >= 1) {
                    dp[j][k][s] = dp[j - 1][k][s] + dp[j - 1][k - 1][s - x[j - 1]];
                }
            }   
        }
    }
    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += dp[N][i][i * A];
    }
    cout << ans << endl;
}

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
    vector<int> x(N + 1);
    int K = A;
    for (int i = 1; i <= N; ++i) {
        cin >> x[i];
        K = max(K, x[i]);
        x[i] -= A;
    }
    K = A;
    vector<vector<ll>> dp(N + 1, vector<ll>(2*K*N + 1, 0));
    dp[0][K*N] = 1;
    for (int j = 0; j <= N; ++j) {
        for (int s = 0; s <= 2*K*N; ++s) {
            if (j >= 1 && x[j] > s) dp[j][s] = dp[j-1][s];
            if (j >= 1 && x[j] <= s) dp[j][s] = dp[j-1][s] + dp[j-1][s-x[j]];
        }
    }
    cout << dp[N][K*N] - 1 << endl;
}

#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;


int main() {
    ll N;
    vector<ll> A;
    vector<char> op;

    cin >> N;
    A.resize(N);
    op.resize(N);
    cin >> A[0];
    for (ll i = 1; i < N; i++) {
        cin >> op[i] >> A[i];
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(3, -1e14));
    dp[1][0] = A[0];
    for (ll i = 1; i < N; i++) {
        if (op[i] == '+') {
            dp[i + 1][2] = dp[i][2] + A[i];
            dp[i + 1][1] = max(dp[i + 1][2], dp[i][1] - A[i]);
            dp[i + 1][0] = max(dp[i + 1][1], dp[i][0] + A[i]);
        } else {
            dp[i + 1][2] = dp[i][1] + A[i];
            dp[i + 1][1] = max({ dp[i + 1][2], dp[i][0] - A[i], dp[i][2] - A[i] });
            dp[i + 1][0] = max(dp[i + 1][1], dp[i][1] + A[i]);
        }
    }

    cout << max({ dp[N][0], dp[N][1], dp[N][2] }) << endl;
}
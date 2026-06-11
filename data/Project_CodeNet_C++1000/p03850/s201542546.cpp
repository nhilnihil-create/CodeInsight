#include <bits/stdc++.h>
using namespace std;
using Int = long long;
Int dp[100010][3];
const Int INF = 1e18;
int main() {
    int N; cin >> N;
    vector<Int> A(N);
    vector<char> op(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i != N - 1) cin >> op[i];
    }
    dp[0][0] = A[0];
    dp[0][1] = dp[0][2] = -INF;
    for (int i = 1; i < N; i++) {
        if (op[i - 1] == '+') {
            dp[i][0] = max({dp[i - 1][0] + A[i], dp[i - 1][1] + A[i], dp[i - 1][2] + A[i]});
            dp[i][1] = max(dp[i - 1][1] - A[i], dp[i - 1][2] - A[i]);
            dp[i][2] = dp[i - 1][2] + A[i];
        } else {
            dp[i][0] = max({dp[i - 1][0] - A[i], dp[i - 1][1] - A[i], dp[i - 1][2] - A[i]});
            dp[i][1] = max({dp[i - 1][0] - A[i], dp[i - 1][1] - A[i], dp[i - 1][1] + A[i], dp[i - 1][2] - A[i], dp[i - 1][2] + A[i]});
            dp[i][2] = max({dp[i - 1][1] + A[i], dp[i - 1][2] - A[i], dp[i - 1][2] + A[i]});
        }
    }
    cout << max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]}) << endl;
    return 0;
}

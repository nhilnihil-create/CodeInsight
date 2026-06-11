#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define INF 1000000000000000000
#define all(x) x.begin(), x.end()
#define PI 3.141592653589793

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));
    dp[0][0] = 0;
    rep(i, N) {
        rep(j, M) {
            dp[i + 1][j] = (dp[i][j] - (ll)j) + (ll)(M - j);
            dp[i][j + 1] = (dp[i][j] - (ll)i) + (ll)(N - i);
        }
    }

    rep(i, N + 1) {
        rep(j, M + 1) {
            if (dp[i][j] == (ll)K) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
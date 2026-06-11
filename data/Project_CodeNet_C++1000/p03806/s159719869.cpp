#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

const int INF = 1e9;

template<class T> inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<vector<int>> dp(505, vector<int>(505, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        for(int j = 404; j >= 0; --j) {
            for(int k = 404; k >= 0; --k) {
                chmin(dp[j + a][k + b], dp[j][k] + c);
            }
        }
    }
    int ans = INF;
    for(int j = 1; j < 505; ++j) {
        for(int k = 1; k < 505; ++k) {
            if(B * j == k * A) {
                chmin(ans, dp[j][k]);
            }
        }
    }
    if(ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}

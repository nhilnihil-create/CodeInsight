#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

const int M = 500, INF = 1e9;

template<class T> inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<vector<int>> dp(M, vector<int>(M, INF));
    dp[0][0] = 0;
    rep(_, N) {
        int a, b, c;
        cin >> a >> b >> c;
        for(int i = M - 1; i >= 0; --i) for(int j = M - 1; j >= 0; --j) {
            if(i + a >= M || j + b >= M) continue;
            chmin(dp[i + a][j + b], dp[i][j] + c);
        }
    }
    int ans = INF;
    rep(i, M) rep(j, M) {
        if(i && j && A * j == B * i) chmin(ans, dp[i][j]);
    }
    if(ans == INF) ans = -1;
    cout << ans << '\n';
    return 0;
}

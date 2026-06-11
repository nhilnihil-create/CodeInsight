#include <bits/stdc++.h>

using namespace std;

#define  N 5005

int dp[N][N];
const int MOD = 1e9 + 7;

void relax(int &x, int y) {
    y %= MOD;
    x += y;
    if (x >= MOD) x -= MOD;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = s.size();
    dp[0][0] = 1;

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {

            //backspace
            if (j == 0) relax(dp[i + 1][0], dp[i][0]);
            else relax(dp[i + 1][j - 1], dp[i][j] * 2);

            relax(dp[i + 1][j + 1], dp[i][j]);
        }
    }
    cout << dp[n][m] << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef qwerty
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif


    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
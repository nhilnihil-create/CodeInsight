#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];

    vector<vector<int>> dp(500, vector<int>(500, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 400; j >= 0; j--) {
            for (int k = 400; k >= 0; k--) {
                dp[j+a[i]][k+b[i]] = min(dp[j+a[i]][k+b[i]], dp[j][k] + c[i]);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= 400; i++) {
        for (int j = 1; j <= 400; j++) {
            if (i * Mb == j * Ma) {
                ans = min(ans, dp[i][j]);
            }
        }
    }

    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
}
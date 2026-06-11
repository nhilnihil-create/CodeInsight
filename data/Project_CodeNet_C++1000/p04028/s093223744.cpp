#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 5050
#define mo 1000000007
char s[N];
int i,j,k,n,m,x,y,dp[N][N],re[N];
inline ll Pow(ll x,ll d) {
    ll ans = 1, y = x;
    for (; d; y = y * y % mo, d >>= 1)d & 1 ? ans = ans * y % mo : 0;
    return ans;
}
int main() {
    re[re[0] = 1] = Pow(2, mo - 2);
    for (i = 2; i < N; ++i)re[i] = 1ll * re[i - 1] * re[1] % mo;
    cin >> n >> s + 1;
    m = strlen(s + 1);
    for (dp[0][0] = i = dp[1][0] = 1, dp[1][1] = 2; i <= n; ++i)
        for (j = 0; j <= i; ++j) {
            if (j)(dp[i + 1][j - 1] += dp[i][j]) %= mo;
            else (dp[i + 1][j] += dp[i][j]) %= mo;
            (dp[i + 1][j + 1] += 2ll * dp[i][j] % mo) %= mo;
        }
    cout << 1ll * dp[n][m] * re[m] % mo << endl;
}
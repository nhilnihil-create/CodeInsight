#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main(void) {
    int n, ma, mb, i, j, k, a[43], b[43], c[43], dp[43][403][403] = {}, ans;
    const int INF = 1e9;

    cin >> n >> ma >> mb;
    for (i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (i = 0; i <= n; i++) for (j = 0; j <= 400; j++) for (k = 0; k <= 400; k++) {
        dp[i][j][k] = INF;
    }

    dp[0][0][0] = 0;

    for (i = 1; i <= n; i++) {
        for (j = 0; j <= 400; j++) for (k = 0; k <= 400; k++) {
            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
            if (j >= a[i - 1] && k >= b[i - 1]) {
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - a[i - 1]][k - b[i - 1]] + c[i - 1]);
            }
        }
    }

    i = 1;
    ans = 1e9;
    while (ma * i <= 400 && mb * i <= 400) {
        ans = min(ans, dp[n][ma * i][mb * i]);
        i++;
    }

    if (ans == 1e9) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }

    return 0;
}
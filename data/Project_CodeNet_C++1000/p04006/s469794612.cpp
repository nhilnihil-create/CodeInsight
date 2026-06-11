#include <bits/stdc++.h>

using namespace std;

int n, k;
long long v[2001];
long long dp[2001][2001], rez;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        dp[i][0] = v[i];
        rez += v[i];
    }
    for (int salt = 1; salt <= n; ++salt) {
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            int pr = i - salt;
            if (pr <= 0) pr += n;
            dp[i][salt] = min(dp[i][salt - 1], v[pr]);
            sum += dp[i][salt];
        }
        rez = min(rez, sum + 1LL * salt * k);
    }
    return cout << rez, 0;
}

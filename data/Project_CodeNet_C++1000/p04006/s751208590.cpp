#include <bits/stdc++.h>
using namespace std;
long long dp[2010][2010];
int main () {
    long long N;
    cin >> N;
    long long x;
    cin >> x;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    for (int i = 0; i < N; i++) {
        long long k = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (i != 0) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = x*j;
            }
            k = min(k, a[(i-j+N)%N]);
            dp[i][j] += k;
        }
    }
    long long ans = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        ans = min(ans, dp[N-1][i]);
    }
    cout << ans << endl;
}
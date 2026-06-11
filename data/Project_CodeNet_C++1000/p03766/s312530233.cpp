#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, P = 1e9 + 7;
int add(int a, int b) {
    return (a += b) >= P ? a - P : a; 
}
typedef long long ll;
int n;
int dp[N], sum[N];
int main() {
    cin >> n;
    dp[0] = 1;
    sum[0] = 1;
    dp[1] = n;
    sum[1] = n + 1;
    for (int k = 2; k <= n; ++k) {
        dp[k] = (ll)(n - 1) * (n - 1) % P;
        dp[k] = add(dp[k], (sum[k - 1] - dp[k - 2] + P) % P);
        dp[k] = add(dp[k], n - k + 1);
        sum[k] = add(sum[k - 1], dp[k]);
    }
    cout << dp[n] << '\n';
    return 0;
}
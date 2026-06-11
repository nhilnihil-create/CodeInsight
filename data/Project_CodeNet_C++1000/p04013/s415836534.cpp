#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[100][3000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, a;
    cin >> n >> a;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        for (int j = i; j > 0; --j) {
            for (int k = a * n; k >= x; k--) {
                dp[j][k] += dp[j - 1][k - x];
            }
        }
    }
    ll nax = 0;
    for (int t = 1; t <= n; ++t) {
        nax += dp[t][a * t];
    }
    cout << nax << "\n";
    return 0;   
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
const ll INF = 1e10;

int main() {
    int n,a; cin >> n >> a;
    vector<int> x(n);
    for (int i = 0; i < n; i ++) cin >> x[i];

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1,vector<ll>(a * n + 1, 0)));
    for (int i = 0; i  < n + 1; i ++ ) dp[i][0][0] = 1;

    for (int i = 0; i < n; i ++ ) {
        int num = x[i];
        for (int j = 1; j < n + 1; j ++) {
            for (int s = 0; s < n * a + 1; s ++) {
                if (s - num >= 0) dp[i + 1][j][s] = dp[i][j][s] + dp[i][j - 1][s - num];
                else dp[i + 1][j][s] = dp[i][j][s];
            }
        }
    }

    ll ans = 0;
    for (ll i = 1; i < n + 1; i ++) {
        ans += dp[n][i][i * a];
    }
    
    cout << ans << endl;
}


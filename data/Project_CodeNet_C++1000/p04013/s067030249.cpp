#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<long long,int> P;

ll dp[55][55][2550];

int main(){
    int n, a;
    cin >> n >> a;
    vector<int> x(n + 1);
    rep(i, n) cin >> x[i + 1];

    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= 2510; k++){
                if (k < x[i]) dp[i][j][k] = dp[i-1][j][k];
                else if (j > 0 && k >= x[i]) dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-x[i]];
                else dp[i][j][k] = 0;
            }
        }
    }
    
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += dp[n][i][a*i];
    }

    cout << ans << endl;
    return 0;
}
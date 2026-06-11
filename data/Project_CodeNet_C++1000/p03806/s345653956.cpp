#include<bits/stdc++.h>
using namespace std;

#define LL long long
int n, x, y; LL ans = 1e9;
int a[45], b[45], c[45]; LL dp[405][405];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

    for(int i = 0; i <= 400; i++)
        for(int j = 0; j <= 400; j++)
            dp[i][j] = 1e9;

    dp[0][0] = 0;
    for(int k = 1; k <= n; k++) 
        for(int i = 400; i >= a[k]; i--)
            for(int j = 400; j >= b[k]; j--)
                dp[i][j] = min(dp[i][j], dp[i-a[k]][j-b[k]] + c[k]);

    for(int i = 1; max(x, y) * i <= 400; i++) ans = min(ans, dp[x*i][y*i]);
    if(ans >= 1e9) cout << -1;
    else cout << ans;        
}
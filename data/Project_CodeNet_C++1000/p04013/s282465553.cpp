#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    i64 n, a;
    cin >> n >> a;
    vector<i64> v;
    for(int i=0;i<n;++i){
        i64 x;
        cin >> x;
        v.push_back(x);
    }
    vector<vector<vector<i64>>> dp(n+1, vector<vector<i64>>(n+1, vector<i64>(2501)));
    dp[0][0][0] = 1;
    for(int i=0;i<n;++i){
        for(int j=0;j<=n;++j){
            for(int k=0;k<=2500;++k){
                dp[i+1][j][k] += dp[i][j][k];
                if(j == n || k+v[i] > 2500)continue;
                dp[i+1][j+1][k+v[i]] += dp[i][j][k];
            }
        }
    }
    i64 ans = 0;
    for(int j=1;j<=n;++j){
        if(a*j > 2500)break;
        ans += dp[n][j][a*j];
    }
    cout << ans << endl;

    return 0;
}
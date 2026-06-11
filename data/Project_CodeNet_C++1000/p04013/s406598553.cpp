#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n,a;
    cin >> n >> a;
    int x[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int dp[n+5][n+5][2505];
    memset(dp,0,sizeof(dp));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k <= 2500; k++) {
                if(i==0 && j==0 && k==0) dp[i][j][k]=1;
                else if(i>=1 && k<x[i-1])dp[i][j][k]=dp[i-1][j][k];
                else if(i>=1 && j>=1 && k>=x[i-1]) dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-x[i-1]];
                else dp[i][j][k]=0;
            }
        }
    }



    int ans=0;
    for(int i = 1; i <= n; i++) {
        int tmp=dp[n][i][i*a];
        ans+=tmp;
//        cout << i << " " << tmp << "\n";
    }
    cout << ans << "\n";

    return 0;
}
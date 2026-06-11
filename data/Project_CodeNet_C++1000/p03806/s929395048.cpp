#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int dp[41][401][401];

int main(){
    int n,A,B;
    cin >> n >> A >> B;
    vector<int> a(n),b(n),c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    rep(i,41) rep(j,401) rep(k,401) dp[i][j][k]=INF;
    dp[0][0][0] = 0;
    rep(i,n){
        rep(j,401){
            rep(k,401){
                if(dp[i][j][k]==INF) continue;
                dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
                dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k] + c[i]);
            }
        }
    }
    int ans = INF;
    for(int j=1;j<=400;j++) for(int k=1;k<=400;k++){
        if(j*A==k*B){
            ans = min(ans,dp[n][k][j]);
            //cout <<"yes" << endl;
        }
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
}
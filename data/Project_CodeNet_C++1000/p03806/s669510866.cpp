#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int dp[50][500][500];

int main(){
    rep(i,50)rep(j,500)rep(k,500) dp[i][j][k] = INF;

    int n,ma,mb;
    scanf("%d %d %d",&n,&ma,&mb);
    vector<int> a(n),b(n),c(n);
    rep(i,n) scanf("%d %d %d",&a[i],&b[i],&c[i]);

    dp[0][0][0] = 0;
    for(int i=0;i<n;i++){
        rep(j,500)rep(k,500){
            if(j+a[i]<500&&k+b[i]<500) dp[i+1][j+a[i]][k+b[i]] = dp[i][j][k] + c[i];
            dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);  
        }
    }
    int ans = INF;

    rep(j,500)rep(k,500){
        if(j==0&&k==0) continue;
        if(k*ma==j*mb) ans = min(ans,dp[n][j][k]);
    }

    printf("%d\n",(ans==INF)?-1:ans);

    return 0;
}
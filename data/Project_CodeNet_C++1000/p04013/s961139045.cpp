#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

//read_kaisetsu
int main() {
    int n,a;cin>>n>>a;
    int x[n];rep(i,n)cin>>x[i];
    sort(x,x+n);
    int m=max(x[n-1],a);
    
    ll dp[n+1][n+1][n*m+1];

//    dp[0][0][0] = 1;
    rep(i,n+1)rep(j,n+1)rep(k,n*m+1){
        if(i==0 && j==0 && k==0)dp[i][j][k]=1;
        else if(i>=1 && k < x[i-1])dp[i][j][k]=dp[i-1][j][k];
        else if(i>=1 && j>=1 && k >= x[i-1])dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-x[i-1]];
        else dp[i][j][k]=0;
    }
    ll ans = 0;
    for(int i=1;i<=n;++i)ans+=dp[n][i][i*a];
    cout<<ans<<endl;
	return 0;
}
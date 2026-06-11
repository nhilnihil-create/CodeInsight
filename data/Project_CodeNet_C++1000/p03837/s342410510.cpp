#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF=1001001001,MX=1010;
int n,m;
int dp[MX][MX],a[MX],b[MX],c[MX];

int main(){
    cin>>n>>m;
    rep(i,MX)rep(j,MX)dp[i][j]=INF;
    rep(i,MX)dp[i][i]=0;
    rep(i,m){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--; b[i]--;
        dp[a[i]][b[i]]=c[i];
        dp[b[i]][a[i]]=c[i];
    }
    //WF
    rep(k,n)rep(i,n)rep(j,n){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    }
    int ans=0;
    rep(i,m){
        bool ok=false;
        rep(j,n)rep(k,n){
            if(dp[j][k]==dp[j][a[i]]+c[i]+dp[b[i]][k])ok=true;
        }
        if(!ok)ans++;
    }
    cout<<ans<<endl;
}
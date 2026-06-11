#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
ll x[MAXN],dif[MAXN],tdif[MAXN],dp[MAXN][60],ind[MAXN],tind[MAXN],n,m,k;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;++i) scanf("%lld",&x[i]);
    scanf("%lld %lld",&m,&k);
    for(int i=1;i<=n;++i) dp[i][0]=i;
    for(int i=1;i<=m;++i){
        ll t;scanf("%lld",&t);
        swap(dp[t][0],dp[t+1][0]);
    }
    for(int j=1;((ll)1<<j)<=k;++j){
        for(int i=1;i<=n;++i){
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=n;++i) ind[i]=i;
    for(int j=59;k;--j){
        if(((ll)1<<j)>k) continue;
        k-=(ll)1<<j;
        for(int i=1;i<=n;++i) tind[i]=dp[ind[i]][j];
        for(int i=1;i<=n;++i) ind[i]=tind[i];
    }
    dif[1]=x[1];
    for(int i=2;i<=n;++i) dif[i]=x[i]-x[i-1];
    for(int i=1;i<=n;++i) tdif[i]=dif[ind[i]];
    for(int i=2;i<=n;++i) tdif[i]+=tdif[i-1];
    for(int i=1;i<=n;++i) printf("%lld\n",tdif[i]);
    return 0;
}
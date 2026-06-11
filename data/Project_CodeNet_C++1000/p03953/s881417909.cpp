#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
ll dif[MAXN],k;
int x[MAXN],dp[MAXN][60],ind[MAXN],tind[MAXN],n,m;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&x[i]);
    scanf("%d %lld",&m,&k);
    for(int i=1;i<=n;++i) dp[i][0]=i;
    for(int i=1;i<=m;++i){
        int tmp;scanf("%d",&tmp);
        swap(dp[tmp][0],dp[tmp+1][0]);
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
    for(int i=1;i<=n;++i) dif[i]=x[ind[i]]-x[ind[i]-1];
    for(int i=2;i<=n;++i) dif[i]+=dif[i-1];
    for(int i=1;i<=n;++i) printf("%lld\n",dif[i]);
    return 0;
}
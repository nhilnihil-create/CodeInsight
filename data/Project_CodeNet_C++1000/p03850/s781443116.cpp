#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const ll inf=1e18;
ll a[maxn];
ll dp[3][maxn];
char op[10];
int main(){
    int n;
    scanf("%d",&n);
    scanf("%lld",&a[1]);
    for(int i=2;i<=n;i++) {
        scanf("%s %lld",op,&a[i]);
        if(op[0]=='-')a[i]=-a[i];
    }
    for(int i=0;i<maxn;i++) dp[1][i]=dp[2][i]=-inf;
    ll ans=0;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=0){
            dp[0][i]=max(max(dp[0][i-1]+a[i],dp[1][i-1]-a[i]),dp[2][i-1]+a[i]);
            dp[1][i]=dp[1][i-1]==-inf?-inf:max(dp[1][i-1]-a[i],dp[2][i-1]+a[i]);
            dp[2][i]=dp[2][i-1]==-inf?-inf:dp[2][i-1]+a[i];
        }else {
            dp[0][i]=max(dp[0][i-1]+a[i],max(dp[1][i-1]-a[i],dp[2][i-1]+a[i]));
            dp[1][i]=max(dp[1][i-1]-a[i],max(dp[0][i-1]+a[i],dp[2][i-1]+a[i]));
            dp[2][i]=max(dp[2][i-1]+a[i],dp[1][i-1]-a[i]);
        }
    }
//    for(int i=1;i<=n;i++) cout<<dp[0][i]<<" ";
//    cout<<endl;
//    for(int i=1;i<=n;i++) cout<<dp[1][i]<<" ";
//    cout<<endl;
    cout<<max(dp[0][n],max(dp[1][n],dp[2][n]))<<endl;
}

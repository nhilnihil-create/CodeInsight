//n种颜色，每种颜色k个球排成一列，将每种颜色最左边的球涂白，求最终状态数
#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int MAX=3e3+5;
const int mod=1e9+7;
int n,k;
int inv[MAX*MAX],fac[MAX*MAX],facinv[MAX*MAX],dp[MAX][MAX];    //已经放了i个白球和j种颜色的球，当前空格放白色或一种新颜色：dp[i][j]=dp[i-1][j]+dp[
inline void pre(){
    fac[0]=facinv[0]=1;
    inv[1]=fac[1]=facinv[1]=1;
    for(int i=2;i<MAX*MAX;i++){
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        fac[i]=fac[i-1]*i%mod;
        facinv[i]=facinv[i-1]*inv[i]%mod;
    }
}
inline int C(int x,int y){
    return (fac[x]*facinv[y]%mod)*facinv[x-y]%mod;
}
signed main(){
    scanf("%lld %lld",&n,&k);
    if(k==1){
        printf("1\n");
        return 0;
    }
    pre();
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j]+(dp[i][j-1]*C(n*k-i-(j-1)*(k-1)-1,k-2)%mod)*(n-j+1)%mod;    //从后面空格中选k-2个放当前颜色，枚举当前颜色
            dp[i][j]%=mod;
        }
    }
    printf("%lld",dp[n][n]);
    return 0;
}

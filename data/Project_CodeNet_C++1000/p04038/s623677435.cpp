#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int p=1e9+7,N=4010,M=4e6+5;
int dp[N][N],fac[M],finv[M],inv[M];
int comb(int n,int m){return n<m?0:fac[n]*1ll*finv[m]%p*finv[n-m]%p;}
int main()
{
    int n=4e6,k;
    fac[1]=fac[0]=finv[1]=finv[0]=inv[1]=1;
    for(int i=2;i<=n;i++)
        inv[i]=(p-p/i)*1ll*inv[p%i]%p,fac[i]=1ll*fac[i-1]*i%p,
        finv[i]=finv[i-1]*1ll*inv[i]%p;
    cin>>n>>k;
    if(k==1){cout<<1<<endl;return 0;}
    dp[1][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i==1&&j==0)continue;
            dp[i][j]=((j!=i)*dp[i-1][j]+
                     (j!=0)*1ll*comb(n-i+(n-j+1)*(k-1)-1,k-2)*dp[i][j-1])%p;
        }
    }
    printf("%lld\n",1ll*dp[n][n]*fac[n]%p);
}

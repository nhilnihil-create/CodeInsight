#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mod 1000000007
using namespace std;
int n,K,m;
int f[2002][2002];
int fac[4000010],inv[4000010];
int quick_pow(int x,int p)
{
    int an=1,po=x;
    while(p)
    {
        if(p&1)  an=1ll*an*po%mod;
        po=1ll*po*po%mod;
        p>>=1;
    }
    return an;
}
int C(int x,int y)
{
    if(x<y)  return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
    fac[0]=1;
    for(int i=1;i<=4000000;i++)  fac[i]=1ll*fac[i-1]*i%mod;
    inv[4000000]=quick_pow(fac[4000000],mod-2);
    for(int i=3999999;i>=0;i--)   inv[i]=1ll*inv[i+1]*(i+1)%mod;
    cin>>n>>K;
    if(K==1)
    {
        puts("1");
        return 0;
    }
    m=n*K;
    f[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i)  f[i][j]=f[i-1][j];
            if(j)  f[i][j]=(f[i][j]+1ll*C(m-(j-1)*(K-1)-i-1,K-2)*f[i][j-1]%mod)%mod;
        }
    }
    int ans=1ll*f[n][n]*fac[n]%mod;
    cout<<ans<<endl;
    return 0;
}
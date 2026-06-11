#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2005,mod=1e9+7;
int C[N*N],f[N],inv[N*N],n,K;
void prework(int n)
{
    inv[1]=1;for(int i=2;i<=n;i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    C[K-2]=1;for(int i=K-1;i<=n;i++)C[i]=1ll*C[i-1]*i%mod*inv[i-K+2]%mod;
}
int main()
{
    scanf("%d%d",&n,&K);
    if(K==1){puts("1");return 0;}
    prework(n*K);
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            f[j]=(f[j]+1ll*f[j-1]*C[n*K-(j-1)*(K-1)-i-1])%mod;
    }
    int ans=f[n];
    for(int i=1;i<=n;i++)ans=1ll*ans*i%mod;
    cout<<ans<<endl;
}
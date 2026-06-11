#include<cstdio>
#include<cstring>
using namespace std;
const long long Mod=1e9+7;
long long n,f[1000005],s[1000005],ans;
int main()
{
    scanf("%lld",&n);
    f[1]=f[2]=f[0]=s[0]=1;s[1]=2;s[2]=3;
    for(long long i=3;i<=n;i++)
    {
        f[i]=(f[i-1]+s[i-3])%Mod;
        s[i]=(s[i-1]+f[i])%Mod;
    }
    long long ans=f[n];
    ans=(ans+1ll*f[n-1]*(n-1)%Mod)%Mod;
    for(int i=0;i<=n-2;i++) ans=(ans+1ll*f[i]*(1ll*(n-1)*(n-1)%Mod+i+1)%Mod)%Mod;
    printf("%lld\n",1ll*ans);
    return 0;
}
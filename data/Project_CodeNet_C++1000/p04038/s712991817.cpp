#include<cstdio>
#include<algorithm> 
#include<cstring>
#define LL long long
using namespace std;
const int N=2e3+5;
const int mod=1e9+7;
int n,m,fac[N*N],inv[N*N],f[N][N];
int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
void Mod(int& a,int b){a+=b;if(a>=mod)a-=mod;}
int power(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)ans=1ll*ans*a%mod;
        a=1ll*a*a%mod;b>>=1;
    }
    return ans;
}
int C(int n,int m){return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
    n=read();m=read();
    if(m==1){printf("1");return 0;}
    fac[0]=1;
    for(int i=1;i<=n*m;i++)fac[i]=1ll*fac[i-1]*i%mod;
    inv[n*m]=power(fac[n*m],mod-2);
    for(int i=n*m;i>=1;i--)inv[i-1]=1ll*inv[i]*i%mod;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
        {
            f[i][j]=f[i-1][j];
            if(!j)continue;
            Mod(f[i][j],1ll*f[i][j-1]*C(n-i+(n-j+1)*(m-1)-1,m-2)%mod);
        }
    printf("%d",1ll*f[n][n]*fac[n]%mod);
    return 0;
}
#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
 
using namespace std;
const int N=2005,mod=1000000007;
typedef long long LL;
int n,k,ans;
LL flv[N*N],inv[N*N],f[N][N];

LL getmi(LL a,int x)
{
    LL rt=1;
    while(x)
    {
        if(x&1) rt=rt*a%mod;
        a=a*a%mod,x>>=1;
    }
    return rt;
}
 
LL C(int n,int m)
{
    return n<m?0:flv[n]*inv[m]%mod*inv[n-m]%mod;
}
 
void inc(LL &x,int y)
{
    if((x+=y)>=mod) x-=mod;
}
 
void task()
{
	if(k==1) {puts("1"); return;}
    flv[0]=1;
    rep(i,1,n*k) flv[i]=flv[i-1]*i%mod;
    inv[n*k]=getmi(flv[n*k],mod-2);
    repd(i,n*k,1) inv[i-1]=inv[i]*i%mod;
    f[0][0]=1;
    rep(i,1,n)
        rep(j,0,i)
        {
            f[i][j]=f[i-1][j];
            if(j) f[i][j]=(f[i][j]+f[i][j-1]*C(n-i+(k-1)*(n-j+1)-1,k-2))%mod;
        }
    printf("%lld\n",flv[n]*f[n][n]%mod);
}
 
int main()
{
    scanf("%d%d",&n,&k);
    task();
    return 0;
}
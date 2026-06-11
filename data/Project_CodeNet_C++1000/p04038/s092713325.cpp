#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
ll p=1000000007;
ll fac[4000010];
ll ifac[4000010];
ll inv[4000010];
void init(int n)
{
    int i;
    fac[0]=fac[1]=ifac[0]=ifac[1]=inv[0]=inv[1]=1;
    for(i=2;i<=n;i++)
    {
        inv[i]=-(p/i)*inv[p%i]%p;
        fac[i]=fac[i-1]*i%p;
        ifac[i]=ifac[i-1]*inv[i]%p;
    }
}
ll c(int x,int y)
{
    if(x<y)
        return 0;
    return fac[x]*ifac[y]%p*ifac[x-y]%p;
}
ll f[2010][2010];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(k<=1)
    {
        printf("1\n");
        return 0;
    }
    init(n*k);
    int i,j;
    f[0][0]=1;
    for(i=1;i<=n;i++)
        for(j=n;j>=0;j--)
        {
            if(j<=i)
                f[i][j]+=f[i-1][j-1]*c(k*i-j-1,k-2)%p;
            f[i][j]=(f[i][j]+f[i][j+1])%p;
        }
    ll ans=(f[n][0]%p+p)%p;
    ans=ans*fac[n]%p;
    printf("%lld\n",ans);
    return 0;
}
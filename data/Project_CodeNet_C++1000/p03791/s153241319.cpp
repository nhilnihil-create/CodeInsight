#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
const int N=1e5+10;
LL n;
int a[N];
LL f[N];
void init()
{
    f[0]=1;
    for(LL i=1;i<=100000;i++)
        f[i]=f[i-1]*i%mod;
}
 
int main()
{
    init();
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    LL ans=1;
    LL b=1;
    LL num=0;
    for(LL i=2;i<=n;i++)
    {
        if(b+2<=a[i])
            b=b+2;
        else
        {
            ans=ans*(i-num)%mod;
            num++;
        }
    }
    ans=ans*f[n-num]%mod;
    printf("%lld\n",ans);
    return 0;
}

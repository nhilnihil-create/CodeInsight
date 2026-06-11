// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define reg register
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
ll x[1000005],xx[1000005],w[1000005],l,r,s,t,n,m,c;
int main()
{
    scanf("%lld%lld%lld",&n,&l,&t);
    for(reg int i=1;i<=n;i++)scanf("%lld%lld",&x[i],&w[i]);
    for(reg int i=1;i<=n;i++)
    {
        if(w[i]==2)w[i]=-1;
        r=x[i]+w[i]*t;
        if (r>0)(c+=r/l)%=n;
        else if(r<0)(c+=(r+1)/l-1)%=n;
        xx[i]=(r%l+l)%l;
    }
    sort(xx+1,xx+n+1);
    c=(c+n)%n;
    for(reg int i=c+1;i<=n;i++)printf("%lld\n",xx[i]);
    for(reg int i=1;i<=c;i++)printf("%lld\n",xx[i]);
    return 0;
}
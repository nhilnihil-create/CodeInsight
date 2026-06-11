//xtwakioi! xtwddYnoi(双重含义)!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=200010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,a[N],P,Q,f[N];
signed main()
{
    n=read();
    for(ri int i=1;i<=n;i++) a[i]=read();
    int now=0;
    for(ri int i=1;i<=n;i++)
    {
        if(i&1ll)
        {
            if(now+a[i]>0) { now+=a[i]; continue; }
            P+=abs(now+a[i])+1, now=1;
        }
        else
        {
            if(now+a[i]<0) { now+=a[i]; continue; }
            P+=abs(now+a[i])+1, now=-1;
        }
    }
    now=0;
    for(ri int i=1;i<=n;i++)
    {
        if(i&1ll)
        {
            if(now+a[i]<0) { now+=a[i]; continue; }
            Q+=abs(now+a[i])+1, now=-1;
        }
        else
        {
            if(now+a[i]>0) { now+=a[i]; continue; }
            Q+=abs(now+a[i])+1, now=1;
        }
    }
    printf("%lld\n",min(P,Q));
    return 0;
}
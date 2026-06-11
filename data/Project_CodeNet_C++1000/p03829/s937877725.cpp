#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=200010, Mod=1e9+7;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int res,n,a[N],A,b;
signed main()
{
    n=read(); A=read(), b=read();
    for(ri int i=1;i<=n;i++) a[i]=read();
    a[0]=a[1];
    for(ri int i=1;i<=n;i++) res+=min(b,(a[i]-a[i-1])*A);
    printf("%lld\n",res);
    return 0;
}
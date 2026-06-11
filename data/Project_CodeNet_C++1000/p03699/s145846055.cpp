//xtwakioi! xtwddYnoi(双重含义)!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=400010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,a[N],res,mi=1e18;
signed main()
{
    n=read();
    int pp=1;
    for(ri int i=1;i<=n;i++)
    {
        int x=read();
        res+=x;
        if(x%10) mi=min(mi,x), pp=0;
    }
    if(pp) { puts("0"); return 0; }
    if(res%10) printf("%lld\n",res);
    else printf("%lld\n",res-mi);
    return 0;
}
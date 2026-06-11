//xtwakioi! xtwddYnoi(双重含义)!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=20010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,T,res,gg;
signed main()
{
    n=read(), T=read();
    for(ri int i=1;i<=n;i++)
    {
        int x=read();
        res+=x+T;
        res-=max(gg,x);
        gg=x+T;
    }
    printf("%lld\n",res);
    return 0;
}
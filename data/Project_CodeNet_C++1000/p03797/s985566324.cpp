//xtwakioi! xtwddYnoi(双重含义)!
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
signed main()
{
    int n,m;
    n=read(), m=read();
    if(m<=2*n) printf("%lld\n",m/2);
    else
    {
        int qwq=m-n*2;
        int t=qwq/4;
        printf("%lld\n",n+t);
    }
    return 0;
}
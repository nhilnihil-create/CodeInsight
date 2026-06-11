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
int n,K;
struct Node { int a,b; }e[N];
inline bool cp(Node x,Node y) { return x.a<y.a; }
signed main()
{
    n=read(), K=read();
    for(ri int i=1;i<=n;i++) e[i].a=read(), e[i].b=read();
    sort(e+1,e+1+n,cp);
    for(ri int i=1;i<=n;i++)
    {
        if(K<=e[i].b) { printf("%lld\n",e[i].a); return 0; }
        K-=e[i].b;
    }
    return 0;
}
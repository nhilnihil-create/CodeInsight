//xtwakioi! xtwddYnoi(双重含义)!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=1010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,m;
struct Edge { int x,y; }a[N],b[N];
signed main()
{
    n=read(), m=read();
    for(ri int i=1;i<=n;i++) a[i].x=read(), a[i].y=read();
    for(ri int i=1;i<=m;i++) b[i].x=read(), b[i].y=read();
    for(ri int i=1;i<=n;i++)
    {
        int dis=1e18, pc=1;
        for(ri int j=1;j<=m;j++)
        {
            if(abs(a[i].x-b[j].x)+abs(a[i].y-b[j].y)<dis)
            {
                dis=abs(a[i].x-b[j].x)+abs(a[i].y-b[j].y);
                pc=j;
            }
        }
        printf("%lld\n",pc);
    }
    return 0;
}
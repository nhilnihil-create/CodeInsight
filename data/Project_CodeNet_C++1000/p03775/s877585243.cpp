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
int qwq=1e18;
signed main()
{
    int n;
    n=read();
    for(ri int i=1;i*i<=n;i++)
    {
        if(n%i) continue;
        int x=i, y=n/i;
        int res,cnt; res=cnt=0;
        while(x) x/=10, cnt++;
        res=max(res,cnt), cnt=0;
        while(y) y/=10, cnt++;
        res=max(res,cnt);
        qwq=min(qwq,res);
    }
    printf("%lld\n",qwq);
    return 0;
}
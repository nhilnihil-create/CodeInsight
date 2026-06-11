//xtwakioi! xtwddYnoi(双重含义)!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=5010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,K,a[N],res,f[N];
signed main()
{
    n=read(), K=read();
    for(ri int i=1;i<=n;i++) a[i]=read(), res+=a[i];
    sort(a+1,a+1+n);
    f[0]=1;
    for(ri int i=n;i;i--)
    {
        int qwq=1;
        for(ri int j=0;j<K;j++) if(f[j]&&j>=K-res) { qwq=0; break; }
        if(qwq) { printf("%lld\n",i); return 0; }  
        for(ri int j=K-1;~j;j--) if(j>=a[i]) f[j]|=f[j-a[i]];
        res-=a[i];
    }
    puts("0");
    return 0;
}
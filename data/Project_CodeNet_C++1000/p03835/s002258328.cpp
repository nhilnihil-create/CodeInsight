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
signed main()
{
    int K,S,res=0;
    K=read(), S=read();
    for(ri int i=0;i<=K;i++)
    for(ri int j=0;i+j<=S&&j<=K;j++)
    if(S-i-j<=K) res++;
    printf("%lld\n",res);
    return 0;
}
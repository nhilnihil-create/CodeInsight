#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
signed main()
{
    int X=read();
    if(X<7) puts("1");
    else
    {
        int res=0;
        res+=(X/11)*2, X%=11;
        res+=(X/10)*2, X%=10;
        res+=(X/9)*2, X%=9;
        res+=(X/8)*2, X%=8;
        res+=(X/7)*2, X%=7;
        if(X) res++;
        printf("%lld\n",res);
    }
    return 0;
}
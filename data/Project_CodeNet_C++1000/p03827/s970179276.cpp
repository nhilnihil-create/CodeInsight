#include <bits/stdc++.h>
#define ri register
//#define int long long
#define E (n+1)
using namespace std; const int N=210;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int res,X;
signed main()
{
    int n;
    string s;
    n=read();
    cin>>s;
    for(ri int i=0;i<n;i++)
    {
        if(s[i]=='I') X++, res=max(res,X);
        if(s[i]=='D') X--, res=max(res,X);
    }
    printf("%lld\n",res);
    return 0;
}
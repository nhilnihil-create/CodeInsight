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
    string s;
    cin>>s;
    int n=s.length();
    int L,R; L=R=-1;
    for(ri int i=0;i<n;i++)
    {
        if(s[i]=='A') { L=i; break; }
    }
    for(ri int i=n-1;~i;i--) if(s[i]=='Z')
    {
        R=i; break;
    }
    if(L<0 || R<0) puts("0");
    else printf("%lld\n",max(R-L+1,0ll));
    return 0;
}
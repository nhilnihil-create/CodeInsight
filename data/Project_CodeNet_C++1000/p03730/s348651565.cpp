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
signed main()
{
    int a,b,c;
    a=read(), b=read(), c=read();
    for(ri int i=1;i<=b;i++)
    {
        if(i*a%b==c) { puts("YES"); return 0; }
    }
    puts("NO");
    return 0;
}
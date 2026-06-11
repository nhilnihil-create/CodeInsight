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
    string a,b,c;
    cin>>a>>b>>c;
    int A=a.length(), B=b.length(), C=c.length();
    if(a[A-1]==b[0] && b[B-1]==c[0]) puts("YES");
    else puts("NO");
    return 0;
}
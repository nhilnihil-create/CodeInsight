//xtwakioi! xtwddYnoi(双重含义)!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=110;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
string a,b;
signed main()
{
    cin>>a>>b;
    int n=a.length(), m=b.length();
    if(n>m) puts("GREATER");
    else if(n<m) puts("LESS");
    else
    {
        for(ri int i=0;i<n;i++)
        {
            if(a[i]<b[i]) { puts("LESS"); return 0; }
            if(a[i]>b[i]) { puts("GREATER"); return 0; }
        }
        puts("EQUAL");
    }
    return 0;
}
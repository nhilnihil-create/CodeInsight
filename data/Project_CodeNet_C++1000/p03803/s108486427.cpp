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
int a,b;
signed main()
{
    a=read(), b=read();
    if(a==1) a+=13;
    if(b==1) b+=13;
    if(a<b) puts("Bob");
    else if(a==b) puts("Draw");
    else puts("Alice");
    return 0;
}
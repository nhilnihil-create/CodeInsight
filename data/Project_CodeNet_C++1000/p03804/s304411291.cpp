#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=210;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,m;
char s[N][N],t[N][N];
signed main()
{
    n=read(), m=read();
    for(ri int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(ri int i=1;i<=m;i++) scanf("%s",t[i]+1);

    for(ri int i=1;i<=n;i++)
    for(ri int j=1;j<=n;j++)
    {
        if(s[i][j]==t[1][1])
        {
            int qwq=1;
            for(ri int x=1;x<=m;x++)
            for(ri int y=1;y<=m;y++)
            if(s[i+x-1][j+y-1]!=t[x][y]) qwq=0;
            if(qwq) { puts("Yes"); return 0; }
        }
    }
    puts("No");
    return 0;
}
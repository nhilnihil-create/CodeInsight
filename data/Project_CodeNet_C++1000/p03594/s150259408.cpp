#include<bits/stdc++.h>
using namespace std;
char mp[4]={'R','G','Y','B'};
int n,m,d,cx,cy;
int main()
{
    scanf("%d%d%d",&n,&m,&d);
    for(register int i=1;i<=n;puts(""),++i)
    for(register int j=1;j<=m;++j)
    cx=i+j+500,cy=i-j+500,printf("%c",mp[cx/d%2+(cy/d%2<<1)]);
    return 0;
}
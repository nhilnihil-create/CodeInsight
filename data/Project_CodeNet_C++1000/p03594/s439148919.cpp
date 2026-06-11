#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char ch[4]={'R','Y','G','B'};
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++) putchar(ch[((i+j)/k&1)<<1|(i-j+m)/k&1]);
        putchar('\n');
    }
    return 0;
}
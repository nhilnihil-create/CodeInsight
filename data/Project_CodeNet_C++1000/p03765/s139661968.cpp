#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
char a[maxn],b[maxn];
int s1[maxn],s2[maxn];
int q;

int main ()
{
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);

    scanf("%s ",a+1);
    scanf("%s ",b+1);

    int na=strlen(a+1);

    for(int i=1; i<=na; ++i)
        if(a[i]=='A')
            s1[i]=s1[i-1]+1;
        else
            s1[i]=s1[i-1]-1;

    int nb=strlen(b+1);

    for(int i=1; i<=nb; ++i)
        if(b[i]=='A')
            s2[i]=s2[i-1]+1;
        else
            s2[i]=s2[i-1]-1;

    scanf("%d ",&q);

    for(int i=1; i<=q; ++i)
    {
        int x,y,z,t;

        scanf("%d %d %d %d ",&x,&y,&z,&t);

        if((s1[y]-s1[x-1]+3*maxn)%3==(s2[t]-s2[z-1]+3*maxn)%3)
            printf("YES\n");
        else
            printf("NO\n");
    }
}

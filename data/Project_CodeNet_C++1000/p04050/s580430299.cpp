#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],tot,id[105];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]&1)tot++,id[tot]=i;
    }
    if(tot>2)return 0*puts("Impossible");
    if(!tot)
    {
        for(int i=1;i<=m;i++)printf("%d ",a[i]);puts("");
        if(m==1)
        {
            printf("2\n%d 1\n",a[1]-1);
        }
        else
        {
            printf("%d\n",m);
            printf("%d ",a[1]-1);
            for(int i=2;i<m;i++)printf("%d ",a[i]);
            printf("%d\n",a[m]+1);
        }
    }
    else if(tot==1)
    {
        swap(a[1],a[id[1]]);

        for(int i=1;i<=m;i++)printf("%d ",a[i]);puts("");
        if(m==1)
        {
            if(a[1]==1)printf("1\n1\n");
            else printf("2\n%d 1\n",a[1]-1);
        }
        else
        {
            printf("%d\n",m-(a[1]==1));
            if(a[1]!=1)printf("%d ",a[1]-1);
            for(int i=2;i<m;i++)printf("%d ",a[i]);
            printf("%d\n",a[m]+1);
        }
    }
    else if(tot==2)
    {
        swap(a[1],a[id[1]]);swap(a[m],a[id[2]]);
        for(int i=1;i<=m;i++)printf("%d ",a[i]);puts("");
        printf("%d\n",m-(a[1]==1));
        if(a[1]!=1)printf("%d ",a[1]-1);
        for(int i=2;i<m;i++)printf("%d ",a[i]);
        printf("%d\n",a[m]+1);
    }
    return 0;
}

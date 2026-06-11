#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],b[N],c[N],tt=0;
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%2)c[++tt]=i;
    }
    if(tt>2){printf("Impossible\n");return 0;}
    else if(tt==1)swap(a[1],a[c[1]]);
    else if(tt==2)swap(a[1],a[c[1]]),swap(a[m],a[c[2]]);
    if(m==1)
    {
        if(a[1]==1)printf("1\n1\n1\n");
        else printf("%d\n2\n%d 1\n",a[1],a[1]-1);
        return 0;
    }
    else
    {
        for(int i=1;i<=m;i++)printf("%d ",a[i]);
        printf("\n%d\n%d ",m-(a[m]==1),a[1]+1);
        for(int i=2;i<m;i++)printf("%d ",a[i]);
        if(a[m]!=1)printf("%d\n",a[m]-1);
    }
}

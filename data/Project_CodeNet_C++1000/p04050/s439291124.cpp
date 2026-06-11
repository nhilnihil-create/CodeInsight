#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int a[maxn],n,m,c[3];
int b=0,tot=0;
int main()
{
    scanf("%d%d",&n,&m);
    c[0]=1;c[1]=m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",a+i);
        if(~a[i]&1)continue;
        c[b++]=i;
        if(b>2){printf("Impossible\n");return 0;}
    }
    swap(a[1],a[c[0]]);swap(a[m],a[c[1]]);
    if(m==1&&a[1]==1){printf("1\n1\n1\n");return 0;}
    for(int i=1;i<=m;i++)printf("%d ",a[i]);
    if(m==1){printf("\n2\n%d 1\n",a[1]-1);return 0;}
    printf("\n%d\n%d ",a[m]>1?m:m-1,a[1]+1);
    for(int i=2;i<m;i++)printf("%d ",a[i]);
    if(a[m]>1) printf("%d\n",a[m]-1);
    return 0;
}
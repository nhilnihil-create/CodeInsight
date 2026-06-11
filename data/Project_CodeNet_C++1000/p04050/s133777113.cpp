#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
vector<int>v;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        if(a[i]&1) v.push_back(i);
    if(v.size()>2) {printf("Impossible\n");return 0;}
    if(v.size()==1) swap(a[v[0]],a[1]);
    else if(v.size()==2) swap(a[v[0]],a[1]),swap(a[v[1]],a[m]);
    if(a[m]==1) swap(a[1],a[m]);
    for(int i=1;i<=m;i++)
        printf(i==m?"%d\n":"%d ",a[i]);
    if(m==1)
    {
        if(a[1]==1) printf("1\n1\n");
        else printf("2\n1 %d\n",a[1]-1);
    }
    else if(a[1]==1&&a[m]==1)
    {
        if(m==2) printf("1\n2\n");
        else
        {
            printf("%d\n",m-1);
            printf("2 ");
            for(int i=2;i<=m-1;i++)
                printf(i==m-1?"%d\n":"%d ",a[i]);
        }
    }
    else
    {
        printf("%d\n",m);
        printf("%d ",a[1]+1);
        for(int i=2;i<=m-1;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[m]-1);
    }
}

#include<bits/stdc++.h>

using namespace std;
const int N=500+7;
struct Node{
    int ind,val;
}node[N];
int a[N*N];
int cmp(Node a,Node b)
{
    return a.ind<b.ind;
}
int main()
{
    int n;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&node[i].ind);
        node[i].val=i;
    }
    sort(node+1,node+n+1,cmp);
    int flag=1,top=1;
    for(int i=1;i<=n&&flag;i++)
    {
        int ind=node[i].ind,val=node[i].val;
        a[ind]=val;
        for(int j=1;j<=val-1;j++)
        {
            while(a[top]) top++;
            a[top]=val;
        }
        if(top>ind)
        {
            flag=0;break;
        }
    }

    for(int i=1;flag&&i<=n;i++)
    {
        int ind=node[i].ind,val=node[i].val;
        for(int j=1;j<=n-val;j++)
        {
            while(a[top]) top++;
            if(top<ind)
            {
                flag=0;break;
            }
            a[top]=val;
        }
    }
    if(flag)
    {
        puts("Yes");
        for(int i=1;i<=n*n;i++)
            printf("%d%c",a[i],i==n*n?'\n':' ');
    }
    else
        puts("No");
    return 0;
}

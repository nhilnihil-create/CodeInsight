#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct edge
{
    int y;
    edge * next;
};
edge * li[100005];
edge * new_edge()
{
    static edge a[200005];
    static int top=0;
    return &a[top++];
}
void inserts(int x,int y)
{
    edge * t=new_edge();
    t->next=li[x];
    t->y=y;
    li[x]=t;
}
void insert_edge(int x,int y)
{
    inserts(x,y);
    inserts(y,x);
}
long long val[100005];
long long tag[100005];
long long sum2[100005];
int deg[100005];
int fa[100005];
void dfs(int x)
{
    edge * t;
    int sum=0;
    for (t=li[x];t!=0;t=t->next)
    {
        if (t->y==fa[x]) continue;
        fa[t->y]=x;
        dfs(t->y);
        if (deg[t->y]>1)
        {
            val[x]-=sum2[t->y]*2;
            sum2[x]+=sum2[t->y];
        }
        sum++;
    }
    if (sum==0)
    {
        tag[x]=val[x];
    }
    if (fa[x]!=-1)
    {
        tag[fa[x]]+=tag[x];
    }
    if (sum!=0)
    {
        val[x]-=tag[x];
    }
    tag[x]=0;
    sum2[x]+=val[x];
}
int res=0;
void dfs2(int x)
{
    edge * t;
    int sum=0;
    long long sum_val=0;
    long long max_val=0;
    for (t=li[x];t!=0;t=t->next)
    {
        if (t->y==fa[x]) continue;
        dfs2(t->y);
        sum++;
        sum_val+=tag[t->y];
        max_val=max(max_val,tag[t->y]);
    }
    if (sum==0)
    {
        tag[x]=val[x];
        return;
    }
    if (val[x]>0)
    {
        res=-1;
    }
    if (val[x]+(sum_val-max_val)<0)
    {
        res=-1;
    }
    if (val[x]+(sum_val/2)<0)
    {
        res=-1;
    }
    sum_val+=val[x]*2;
    tag[x]=sum_val;
    return;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        val[i]=t;
    }
    int root=-1;
    for (i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        deg[x]++;
        deg[y]++;
        if (deg[x]>=2) root=x;
        if (deg[y]>=2) root=y;
        insert_edge(x,y);
    }
    if (n==2)
    {
        if (val[0]==val[1])
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
        return 0;
    }
    fa[root]=-1;
    dfs(root);
    dfs2(root);
    if (tag[root]!=0) res=-1;
    if (res==-1)
    {
        puts("NO");
    }
    else
    {
        puts("YES");
    }
    return 0;
}

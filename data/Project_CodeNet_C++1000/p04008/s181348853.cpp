#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define N 100050
#define res register int
using namespace std;
int head[N*2],n,m,k,tot;
int a[N],ans;

struct data{
    int to,nxt;
}edge[N*2];

inline void add(int x,int y)
{
    edge[++tot].to=y;
    edge[tot].nxt=head[x];
    head[x]=tot;
}

inline int dfs(int root,int deth)
{
    int p=deth;
    for(res i=head[root];i;i=edge[i].nxt)
    p=max(p,dfs(edge[i].to,deth+1));
    if(a[root]!=1&&p-deth==m-1) return ans++,0;
    else return p;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(res i=1;i<=n;i++)
    scanf("%d",&a[i]);

    if(a[1]!=1)
    {
        a[1]=1;
        ans=1;
    }

    for(res i=2;i<=n;i++)
    add(a[i],i);

     dfs(1,0);
     printf("%d",ans);
}
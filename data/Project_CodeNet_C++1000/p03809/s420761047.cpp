#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
const int MAXN=1e5+10;
int A[MAXN],deg[MAXN]={0};
typedef long long LL;
LL cntfa[MAXN];
vector<int> ed[MAXN];
bool flag=true;
int root=0;
void dfs(int x,int fa=0)
{
    if(deg[x]==1)
    {
        cntfa[x]=A[x];
        return;
    }
    LL sum=0;
    for(int i=0;i<ed[x].size();i++) if(ed[x][i]!=fa)
    {
        dfs(ed[x][i],x);
        if(cntfa[ed[x][i]]>A[x]) flag=false;
        sum+=cntfa[ed[x][i]];
    }
    if(x!=root)
    {
        cntfa[x]=2*A[x]-sum;
        if(cntfa[x]<0||cntfa[x]>A[x]) flag=false;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&A[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
        deg[u]++;deg[v]++;
    }
    if(n==2)
    {
        if(A[1]==A[2]) puts("YES");else puts("NO");
        return 0;
    }
    for(int i=1;i<=n;i++) if(deg[i]>1) root=i;
    dfs(root);
    LL sum=0;
    for(int i=0;i<ed[root].size();i++) sum+=cntfa[ed[root][i]];
    if(sum!=2*A[root]) flag=false;
    for(int i=0;i<ed[root].size();i++) if(cntfa[ed[root][i]]>A[root]) flag=false;
    if(flag) puts("YES");else puts("NO");
    return 0;
}

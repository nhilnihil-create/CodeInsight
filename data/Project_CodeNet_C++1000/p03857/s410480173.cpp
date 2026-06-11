#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int head[N],cnt,fa[N],vis[N],ans[N];
struct node{
    int t,next;
} e[N];

void init()
{
    memset(head,-1,sizeof(head));
    cnt=0;
}
void add(int u,int v)
{
    e[cnt]=node{v,head[u]};
    head[u]=cnt++;
}


int father(int x)
{
	return x==fa[x]?x:fa[x]=father(fa[x]);
}

int join(int x,int y)
{
	x=father(x);
	y=father(y);
	if(x!=y)
		fa[x]=y;
}

void initfa(int n)
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
}
 
 
void dfs1(int u,int tag,map<int ,int > &M)
{
    if(vis[u]==tag)return;
    vis[u]=tag;
    M[father(u)]++;
    for(int i=head[u];~i;i=e[i].next)
        dfs1(e[i].t,tag,M);
}
 
void dfs2(int u,int tag,map<int ,int > &M)
{
    if(vis[u]==tag)
		return;
    vis[u]=tag;
    ans[u]+=M[father(u)];
    for(int i=head[u];~i;i=e[i].next)
        dfs2(e[i].t,tag,M);
}
 
int main()
{	int n,k,L,u,v;
    cin>>n>>k>>L;
    init();
    initfa(n);
    while(k--)
	{
        cin>>u>>v;
        join(u,v);
    }
    while(L--)
	{
        cin>>u>>v;
        add(u,v);add(v,u);
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) 
		if(!vis[i])
    	{
    	    map<int ,int > M;
    	    dfs1(i,i,M);
    	    dfs2(i,-i,M);
    	}
    for(int i=1;i<=n;i++)
        printf("%d%c",ans[i],i<n?' ':'\n');
}
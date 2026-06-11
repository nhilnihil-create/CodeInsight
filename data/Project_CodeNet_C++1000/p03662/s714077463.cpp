#include<cstdio>
#include<vector>

const int N=100010;

int n,fa[N],dep[N],sz[N],a[N],sa,b[N],sb;
std::vector<int> G[N];

void dfs(int u)
{
	sz[u]=1;
	for(auto v:G[u])if(v^fa[u])
		fa[v]=u,dep[v]=dep[u]+1,dfs(v),sz[u]+=sz[v];
}

int main()
{
	scanf("%d",&n);
	if(n==1)
		return puts("Fennec"),0;
	for(int i=1,x,y; i<n; i++)
	{
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1);
	int lca=0;
	for(int u=1,v=n;;){
		if(dep[u]>dep[v])u=fa[u];
		else v=fa[v];
		if(u==v){
			lca=u;
			break;
		}
	}
	for(int x=1; x!=fa[lca]; x=fa[x])
		a[++sa]=x;
	for(int y=n; y!=lca; y=fa[y])
		b[++sb]=y;
	for(;sb;--sb)a[++sa]=b[sb];
	int p=a[(sa+1)/2];
	int q=a[(sa+1)/2+1];
	int s1=1,s2=0;
	if(p==fa[q])
	{
		s2=sz[q];
		s1=n-s2;
	}
	if(q==fa[p])
	{
		s1=sz[p];
		s2=n-s1;
	}
	if(s1>s2)
		puts("Fennec");
	else
		puts("Snuke");
	return 0;
}

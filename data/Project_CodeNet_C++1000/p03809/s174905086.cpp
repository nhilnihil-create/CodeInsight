#include<cstdio>
#include<cstdlib>
#include<vector>
const int N=1e5+3;
int n,a[N],rt,s,f[N];
std::vector<int>g[N];
void Dfs(int u,int fa){
	int v;
	for(int i=0;i<g[u].size();i++)if((v=g[u][i])!=fa)
	  a[u]-=a[v],Dfs(v,u);
}
void Dfs1(int u,int fa){
	int v,mx=0;
	for(int i=0;i<g[u].size();i++)if((v=g[u][i])!=fa)
	  Dfs1(v,u),f[u]+=f[v],mx=std::max(mx,f[v]);
	if(g[u].size()>1&&a[u]>0)exit(0*puts("NO"));
	if(g[u].size()>1&&a[u]<0){
	  if(std::min(f[u]-mx,f[u]/2)<-a[u])exit(0*puts("NO"));
	  f[u]+=a[u]*2;
	  a[fa]-=a[u],a[u]=0;
	}
	if(g[u].size()==1)f[u]=a[u];
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(u=1;u<=n;u++)scanf("%d",a+u);
	for(int i=1;i<n;i++)
	  scanf("%d%d",&u,&v),
	  g[u].push_back(v),g[v].push_back(u);
	if(n==2)return 0*puts(a[1]==a[2]?"YES":"NO");
	for(u=1;u<=n;u++)if(g[u].size()>1)rt=u;
	a[0]-=a[rt],Dfs(rt,0);
	Dfs1(rt,0);
	return 0*puts(a[0]?"NO":"YES");
}
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> P;
const int MAXN=2e5+10;
map<P,int> mp;
struct edge{int nxt,to;}e[MAXN<<2];
int c1[MAXN],c2[MAXN],sum1[MAXN],sum2[MAXN];
int n,k,l,x,y,head[MAXN],vis[MAXN],res[MAXN],tot,cnt;

void add_edge(int from,int to)
{
	e[++tot].nxt=head[from];e[tot].to=to;head[from]=tot;
	e[++tot].nxt=head[to];e[tot].to=from;head[to]=tot;
}

void dfs(int x,int c,int* col)
{
	vis[x]=true;col[x]=c;
	for(int i=head[x];i;i=e[i].nxt)
		if(!vis[e[i].to]) dfs(e[i].to,c,col);
}

void solve(int esum,int* col)
{
	tot=cnt=0;
	memset(head,0,sizeof(head));
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=esum;i++)
		scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1;i<=n;i++)
		if(!vis[i]) dfs(i,++cnt,col);
}

int main()
{
	scanf("%d%d%d",&n,&k,&l);
	memset(res,0x3f,sizeof(res));
	solve(k,c1);solve(l,c2);
	for(int i=1;i<=n;i++)
		sum1[c1[i]]++,sum2[c2[i]]++;
	for(int i=1;i<=n;i++) 
		mp[P(c1[i],c2[i])]++;
	for(int i=1;i<=n;i++)
		printf("%d ",mp[P(c1[i],c2[i])]);
	
	return 0;
}
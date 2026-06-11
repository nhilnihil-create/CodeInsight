#include <bits/stdc++.h>
using namespace std;
int n,m,Q,u[100010],d[100010],t=0,c[100010],Link[100010],color[100010][15];
vector <int> edge[100010];
struct dsa
{
	int v,nex;
}e[200010];
void Insert(int xx,int yy) {e[++t].nex=Link[xx];e[t].v=yy;Link[xx]=t;}
void dfs(int now,int dis,int col)
{
	if (dis==-1) return;
	if (color[now][dis]) return;
	color[now][dis]=col;
	for (int i=0;i<edge[now].size();i++) 
	  dfs(edge[now][i],dis-1,col);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		edge[xx].push_back(yy);
		edge[yy].push_back(xx);
	}
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++)
	  scanf("%d%d%d",&u[i],&d[i],&c[i]);
	for (int i=1;i<=n;i++)	edge[i].push_back(i);
	for (int i=Q;i;i--)
	  dfs(u[i],d[i],c[i]);
	for (int i=1;i<=n;i++)
	  printf("%d\n",color[i][0]);
}
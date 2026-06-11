#include <bits/stdc++.h>
using namespace std;
int t=0,n,k,ans,p,Link[2010]; 
struct dsa {int x,y;}a[2010];
struct edge{int nex,v;}e[4010];
void Insert(int xx,int yy) {e[++t].nex=Link[xx];e[t].v=yy;Link[xx]=t;}
void dfs(int now,int fa,int len) 
{
	if (len>k/2) ans++;
	for (int i=Link[now];i;i=e[i].nex) {
		if (e[i].v==fa||e[i].v==p) continue;
		dfs(e[i].v,now,len+1);
	}
	return ;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++) {
		scanf("%d%d",&a[i].x,&a[i].y);
		Insert(a[i].x,a[i].y);
		Insert(a[i].y,a[i].x);
	}
	if (k&1) {
		int Min=1e9;
		for (int i=1;i<n;i++) {
			ans=0;
			p=a[i].y;dfs(a[i].x,0,0);
			p=a[i].x;dfs(a[i].y,0,0);
			Min=min(ans,Min);
		}
		printf("%d\n",Min);
	}
	else {
		int Min=1e9;
		for (int i=1;i<=n;i++) {
			ans=0;
			dfs(i,0,0);
			Min=min(ans,Min);
		}
		printf("%d\n",Min);
	}
	return 0;
}
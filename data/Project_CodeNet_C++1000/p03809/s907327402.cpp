#include<bits/stdc++.h>

using namespace std;

const int maxn=2e5+10;

int head[maxn],num;
struct Le
{
	int nt,to;
}edge[maxn];
int a[maxn],n,du[maxn],rt;
void add(int f,int t) {
	edge[++num].nt=head[f];
	edge[num].to=t;
	head[f]=num;
}
int dfs(int u,int fa) {
	if(du[u]==1) return a[u];
	int sy=a[u]<<1;
	for(int i=head[u];i;i=edge[i].nt) {
		int v=edge[i].to;
		if(v==fa) continue ;
		int x=dfs(v,u);
		if(x>a[u]) {
			puts("NO");exit(0);
		} 
		sy-=x;
	}
	if(sy<0||sy>a[u]) {
		puts("NO");exit(0);
	}
	return sy;
} 

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
		du[u]++;du[v]++;
		if(du[u]>1) rt=u;
		if(du[v]>1) rt=v;
	}
	if(n==2) {
		if(a[1]==a[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	if(dfs(rt,0)) puts("NO");
	else puts("YES");
	return 0;
}


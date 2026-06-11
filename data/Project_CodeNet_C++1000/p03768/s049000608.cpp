#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct aaa{
	int x,y,w;
}a[500001];
int n,m,t1,tot,ans[500001],mx[500001],e[500001],nt[500001],hd[500001];
void dfs(int x,int dep,int w){
	if(mx[x]>=dep)return;
	mx[x]=dep;
	if(!ans[x])ans[x]=w;
	if(!w)return;
	int i;
	for(i=hd[x];i;i=nt[i])dfs(e[i],dep-1,w);
}
void build(int x,int y){
	tot++;
	e[tot]=y;
	nt[tot]=hd[x];hd[x]=tot;
}
int main(){
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)mx[i]=-1;
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		build(x,y);build(y,x);
	}
	scanf("%d",&t1);
	for(i=1;i<=t1;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
	for(i=t1;i;i--)dfs(a[i].x,a[i].y,a[i].w);
	for(i=1;i<=n;i++)printf("%d\n",ans[i]);
}
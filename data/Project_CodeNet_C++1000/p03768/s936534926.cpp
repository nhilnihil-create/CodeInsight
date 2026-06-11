#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct aaa{
	int x,y,fr;
}a[1000001];
int n,m,t1,tot,ans[1000001],e[1000001],nt[1000001],hd[1000001],mx[1000001];
void add(int x,int y){
	tot++;
	e[tot]=y;
	nt[tot]=hd[x];hd[x]=tot;
}
void dfs(int x,int dep,int col){
	if(!ans[x])ans[x]=col;
	if(mx[x]>=dep)return;
	mx[x]=dep;
	int i;
	for(i=hd[x];i;i=nt[i])dfs(e[i],dep-1,col);
}
int main(){
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	scanf("%d",&t1);
	for(i=1;i<=t1;i++)scanf("%d%d%d",&a[i].fr,&a[i].x,&a[i].y);
	for(i=t1;i;i--)dfs(a[i].fr,a[i].x,a[i].y);
	for(i=1;i<=n;i++)printf("%d\n",ans[i]);
}
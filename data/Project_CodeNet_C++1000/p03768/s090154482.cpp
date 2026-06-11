#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct aaa{
	int x,y,d;
}a[500010];
int n,m,t1,tot,e[500010],hd[500010],nt[500010],f[500010],b[500010];
void build(int x,int y){
	tot++;
	e[tot]=y;
	nt[tot]=hd[x];hd[x]=tot;
}
void dfs(int x,int dep,int co){
	int i;
	if(!b[x])b[x]=co;
	if(dep<=f[x])return;
	f[x]=dep;
	for(i=hd[x];i;i=nt[i])dfs(e[i],dep-1,co);
}
int main(){
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		build(x,y);build(y,x);
	}
	scanf("%d",&t1);
	for(i=1;i<=t1;i++)scanf("%d%d%d",&a[i].x,&a[i].d,&a[i].y);
	for(i=t1;i;i--){
		dfs(a[i].x,a[i].d,a[i].y);
	}
	for(i=1;i<=n;i++)printf("%d\n",b[i]);
}
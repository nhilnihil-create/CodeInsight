#include<bits/stdc++.h>
#define ll long long
#define N 100009
#define M 400009
using namespace std;

int n,m,tot,sz,fst[N],pnt[M],nxt[M],vis[N]; bool flag;
void add(int x,int y){
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
}
void dfs(int x,int t){
	if (!vis[x]){
		sz++; vis[x]=t;
	} else{
		if (vis[x]!=t) flag=1; 
		return;
	}
	int i;
	for (i=fst[x]; i; i=nxt[i])
		dfs(pnt[i],t^3);
}
int main(){
	scanf("%d%d",&n,&m);
	int i,x,y;
	for (i=1; i<=m; i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	ll t1=0,t2=0,t3=0;
	for (i=1; i<=n; i++) if (!vis[i]){
		sz=0; flag=0;
		dfs(i,1);
		if (sz==1) t1++; else
		if (flag) t2++; else t3++;
	}
	printf("%lld\n",t1*(n-t1)*2+t2*t3*2+t1*t1+t2*t2+t3*t3*2);
	return 0;
}

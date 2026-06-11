/*
D - Teleporter
by.YXH_XianYu
   2018.6.20
 */
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define rep(i,j,k) for(int i=j,lim=k;i<=lim;i++)
#define MXN 200003

int n,k,a,ans;

struct Edge{
	int to,
		next;
}e[MXN];
int tot,last[MXN];
void Add(int u, int v){
	tot++;
	e[tot].to=v;
	e[tot].next=last[u];
	last[u]=tot;
}

int fa[MXN],deg[MXN],dep[MXN],
	q[3*MXN],hd,tl;
int main(){
	//freopen("Teleporter.in","r",stdin);
	//freopen("Teleporter.out","w",stdout);

	scanf("%d%d",&n,&k);
	scanf("%d",&a);
	if(a!=1)ans++;
	rep(i,2,n){
		scanf("%d",&a);
		fa[i]=a;
		deg[a]++;
	}
	rep(i,2,n)if(deg[i]==0)q[++tl]=i;
	while(hd<tl){
		hd++;
		int fj=q[hd];
		if(fj==1)
			break;
		if(fa[fj]!=1 && dep[fj]==k-1)
			ans++;
		else
			dep[fa[fj]]=std::max(dep[fa[fj]],dep[fj]+1);
		deg[fa[fj]]--;
		if(deg[fa[fj]]==0)
			q[++tl]=fa[fj];
	}
	printf("%d\n",ans);

	return 0;
}

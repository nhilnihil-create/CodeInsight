#include<iostream>
#include<stdio.h>
#include<string.h>
#define N 520000
using namespace std;
int Next[N],h[N],v[N];
int tot,p[N],siz[N],dep[N],flag;
int f[N];
int n,m;
long long k,o,ans,OO;
int add(int x,int y){
	tot++;
	Next[tot]=h[x];
	v[tot]=y;
	h[x]=tot;
}
int dfs(int x,int fa,int c){
	p[x]=c;
	siz[x]=1;
	dep[x]=dep[fa]+1;
	for(int i=h[x];i;i=Next[i]){
		if(v[i]==fa)continue;
		if(p[v[i]]&&((dep[x]-dep[v[i]])%2==0)){
			flag=1;
			continue;
		}
		if(p[v[i]])continue;
		dfs(v[i],x,c);
		siz[x]+=siz[v[i]];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		if(p[i]==0){
			flag=0;
			dfs(i,0,i);
			if(siz[i]==1)k++;
			else o++;
			f[i]=flag;
			OO+=flag;
		}
	}
	ans+=k*n;
	for(int i=1;i<=n;i++){
		if(p[i]==i)if(siz[i]!=1){
			if(f[i])ans+=o;
			else ans+=2*o-OO;
		}
		if(p[i]==i)if(siz[i]==1)ans+=n-k;
	}
	printf("%lld\n",ans);
} 
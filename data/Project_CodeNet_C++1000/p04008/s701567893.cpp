#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 220000
using namespace std;
struct node{
	int x,y;
}q[N];
int dep[N],p[N],a[N],f[N][21];
int Next[N],h[N],v[N],tot,k,n;
int dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=h[x];i;i=Next[i]){
		if(v[i]==fa)continue;
		dfs(v[i],x);
	}
}
bool cmp(node x,node y){
	return x.y>y.y;
}
int lfs(int x){
	if(p[x]==1)return 0;
	p[x]=1;
	for(int i=h[x];i;i=Next[i]){
		if(dep[v[i]]<dep[x])continue;
		lfs(v[i]);
	}
}
int add(int x,int y){
	tot++;
	Next[tot]=h[x];
	v[tot]=y;
	h[x]=tot;
}
int find(int x,int k){
	for(int i=20;i>=0;i--)if(dep[f[x][i]]>=k)x=f[x][i];
	return x;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i>=2)add(i,a[i]),add(a[i],i);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)q[i].x=i,q[i].y=dep[i];
	sort(q+1,q+1+n,cmp);
	int ans=0;
//	for(int i=1;i<=n;i++)printf("%d %d\n",q[i].x,q[i].y);
//	printf("\n");
	for(int i=1;i<=n;i++){
		int o=q[i].x;
		if(p[o]==1)continue;
		if(dep[o]<=1+k)continue;
		o=find(o,dep[o]-k+1);
//		printf("%d %d\n",q[i].x,o);
		lfs(o);
		ans++;
	}
	if(a[1]!=1)ans++;
	printf("%d\n",ans);
}
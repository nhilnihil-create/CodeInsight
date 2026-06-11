#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
#define rg register
#define ll long long
#define LDB long double
#define ull unsigned long long
#define view(i,x) for(rg int i=hd[x];i!=-1;i=e[i].nt)
#define go(i,x,a) for(rg int i=a;i<x;i++)
#define inf 0x3f3f3f3f
#define INF 0x7fffffff
using namespace std;

const int maxn=1e5+5;
int n,K,fa[maxn],dep[maxn],k,hd[maxn],mx[maxn];
ll ans=0;
struct edd{
	int nt,v;
}e[maxn*2];

inline int rd(){
	int ret=0,af=1; char gc=getchar();
	while(gc < '0' || gc > '9'){ if(gc=='-') af=-af; gc=getchar(); }
	while(gc >= '0' && gc <= '9') ret=ret*10+gc-'0',gc=getchar();
	return ret*af;
}

inline void add(int a,int b){
	e[k].v=b; e[k].nt=hd[a]; hd[a]=k++;
}

void dfs(int x,int f){
	dep[x]=dep[f]+1; mx[x]=dep[x];
	for(rg int i=hd[x];i!=-1;i=e[i].nt){
		int v=e[i].v;
		dfs(v,x);
		mx[x]=max(mx[x],mx[v]);
	}
	if(fa[x] != 1 && mx[x]-dep[x] == K-1) mx[x]=0,ans++;
}

int main(){
	memset(hd,-1,sizeof(hd)); k=0;
	n=rd(); K=rd();
	go(i,n+1,1)	fa[i]=rd();
	if(fa[1] != 1) ans++,fa[1]=1;
	go(i,n+1,2)	add(fa[i],i);
	dep[0]=-1; dfs(1,0);
	printf("%lld",ans);
	return 0;
}//Faze

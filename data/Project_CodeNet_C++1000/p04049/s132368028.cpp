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

const int maxn=2005;
int n,m,K,k,hd[maxn],ans,tt;
struct edd{
	int nt,v;
}e[maxn*maxn*2];

inline int rd(){
	int ret=0,af=1; char gc=getchar();
	while(gc < '0' || gc > '9'){ if(gc=='-') af=-af; gc=getchar(); }
	while(gc >= '0' && gc <= '9') ret=ret*10+gc-'0',gc=getchar();
	return ret*af;
}

inline void add(int a,int b){
	e[k].v=b; e[k].nt=hd[a]; hd[a]=k++;
}

void dfs(int x,int fa,int d){
	if(d <= K/2) tt++;
	view(i,x){
		int v=e[i].v; if(v == fa) continue;
		dfs(v,x,d+1);
	}
}

int main(){
	memset(hd,-1,sizeof(hd)); k=0;
	n=rd(); K=rd(); int a,b;
	go(i,n,1){
		a=rd(); b=rd();
		add(a,b); add(b,a);
	}
	int ans=0;
	if(K%2 == 0){
		go(i,n+1,1){
			dfs(i,0,0);
			ans=max(ans,tt); tt=0;
		}
	}else{
		for(rg int i=0;i<k;i+=2){
			int u=e[i].v,v=e[i^1].v;
			dfs(u,v,0); dfs(v,u,0);
			ans=max(ans,tt); tt=0;
		}
	}
	printf("%d",n-ans);
	return 0;
}//Faze

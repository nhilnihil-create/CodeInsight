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

const int maxn=2e5+5;
int n,m,a[maxn],hd[maxn],k,in[maxn],rt;
int fl=0,tl;
ll up[maxn],q[maxn];
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
	e[k].v=a; e[k].nt=hd[b]; hd[b]=k++;
}

void dfs(int x,int fa){
	int sz=0;
	for(rg int i=hd[x];i!=-1;i=e[i].nt){
		int v=e[i].v; if(v == fa) continue;
		sz++;
		dfs(v,x);
		if(fl) return ;
	}
	if(sz == 0) up[x]=a[x];
	else{
		tl=0; ll ss=0,d,f,sf=0;
		for(rg int i=hd[x];i!=-1;i=e[i].nt){
			int v=e[i].v; if(v == fa) continue;
			q[++tl]=up[v]; ss=ss+up[v];
		}
		if(a[x]>ss){
			fl=1;return;
		}
		f=1ll*2*a[x]-ss; d=ss-f;
		if(f < 0 || d%2 != 0){ fl=1; return ; }
		go(i,tl+1,1)
			sf=sf+(q[i] > d/2 ? q[i]-d/2 : 0);
		if(sf > f){ fl=1; return ; }
		up[x]=f;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("data.in","r",stdin);
	//freopen("1.out","w",stdout);
	#endif
	memset(hd,-1,sizeof(hd)); k=0;
	n=rd(); int x,y;
	go(i,n+1,1) a[i]=rd();
	go(i,n,1){ x=rd(); y=rd(); add(x,y); in[x]++; in[y]++; }
	if(n == 2){
		if(a[1] != a[2]) puts("NO");
		else puts("YES");
		return 0;
	}
	go(i,n+1,1)
		if(in[i] != 1){ rt=i; break; }
	dfs(rt,0);
	if(up[rt] != 0) fl=1;
	if(fl) puts("NO");
	else puts("YES");
	return 0;
}//Faze

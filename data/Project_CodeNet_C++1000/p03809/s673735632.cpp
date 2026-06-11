#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=1e5+11;
struct Edge{
	int v;Edge *nex;
}pl[N<<1],*cur=pl,*G[N];
void ins(int u,int v){
	cur->v=v,cur->nex=G[u],G[u]=cur++;
}
int n,A[N],d[N],f[N],g[N];
void dfs(int x,int fa=0){
	int th=0,mx=0;
	Es(x,i)if(i->v!=fa){
		dfs(i->v,x);
		g[x]+=g[i->v];
		f[x]+=f[i->v];
		mx=max(mx,g[i->v]-f[i->v]);
		th+=g[i->v]-f[i->v];
	}
	if(!g[x]){
		g[x]=A[x];return;
	}else if(th<A[x]){
		puts("NO");
		exit(0);
	}
	if(th>2*A[x]||mx>A[x]){
		puts("NO");
		exit(0);
	}
	f[x]+=2*(th-A[x]);
}
int main(){
	n=rd();
	rep(i,1,n)A[i]=rd();
	rep(i,2,n){
		int u=rd(),v=rd();
		ins(u,v),ins(v,u);
		d[u]++,d[v]++;
	}
	if(n==2){
		return puts(A[1]==A[n]?"YES":"NO"),0;
	}
	int rt;
	rep(i,1,n){
		if(d[i]^1){
			rt=i;
			break;
		}
	}
	dfs(rt);
	puts(f[rt]==g[rt]?"YES":"NO");
}
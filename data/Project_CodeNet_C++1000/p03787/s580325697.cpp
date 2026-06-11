#include <bits/stdc++.h>
#define pb push_back
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;
 
#define Pr(f,...) fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)
 
const int N=3e5+50,M=1<<18,P=1e9+7; 
 
int n,m,p[N],vis[N],col[N];
vector<int> g[N]; 
 
bool fail;
void dfs(int v,int c=0){
	col[v]=c;
	for(int d:g[v]){
		if(col[d]==-1){
			dfs(d,c^1);
		}else{
			if((col[d]^col[v])!=1)fail=true;
		}
	}
}
 
int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	//freopen("dat.in","r",stdin); 
	//freopen("my.out","w",stdout); 
#endif
	scanf("%d%d",&n,&m); 
	rep(i,1,n){
		p[i]=i;
	}
	rep(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v); 
		g[u].pb(v),g[v].pb(u); 
	}
	long long x=0,y=0,z=0,ans=0;
	memset(col,-1,sizeof(col)); 
	rep(i,1,n){
		if(col[i]==-1){
			fail=false,dfs(i); 
			if(g[i].empty())++z;
			else{
				x+=!fail;
				y+=fail;
			}
		}
	}
	ans+=z*n+x*x*2+2*x*y+y*y+(n-z)*z;
	printf("%lld\n", ans);
}
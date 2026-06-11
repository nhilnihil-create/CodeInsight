#include <bits/stdc++.h>
#define pb push_back
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=gg[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;

typedef long long ll;

const int N=2e5+50,P=1e9+7,K=5,oo=0x3f3f3f3f;

int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }

int n;
vector<int> g[N];
int dfs(int v,int p){
	int res=0;
	for(int d:g[v]){
		if(d!=p){
			int x=dfs(d,v);
			res^=x+1;
		}
	}
	return res;
}

int main(int argc,char *argv[]){
#ifdef CCURIOUSCAT
	freopen("dat.in","r",stdin);
	freopen("my.out","w",stdout);
#endif
	scanf("%d",&n); 
	rep(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u); 
	}
	int res=dfs(1,0);
	puts(res!=0?"Alice":"Bob"); 
	return 0;
}
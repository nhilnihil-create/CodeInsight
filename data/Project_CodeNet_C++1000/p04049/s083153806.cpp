#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f,oo = inf;
#define pi 3.14159265358979323846
#define IL inline
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define Rep(i,a,b) for(int i=(a);i<=(b);++i)
#define Dep(i,a,b) for(int i=(a);i>=(b);--i)
#define pc putchar
#define gc getchar
IL ll read(){
    ll x=0;char f=0;char c=gc();
    for(;!isdigit(c);c=gc())f|=(c=='-');
    for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
    return f?-x:x;
}
IL void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);pc(x%10+'0');}
IL void writeln(ll x){write(x);pc('\n');}
IL void wri(ll x){write(x),pc(' ');}
#define debug(x) printf(#x" = %d\n",x);
#define rd() read()
#define rdb() readdb()
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))
#define y1 ____y1
#define hash __hash
#define union _union
#define ramdom ((double)rand() / RAND_MAX)
#define x first
#define y second
const int maxn = 300030;
struct Edge{
	int to,nxt;
	Edge(){}
	Edge(int to,int nxt):to(to),nxt(nxt){}
}edge[maxn*2];
int first[maxn],nume;
void Addedge(int a,int b){
	edge[nume] = Edge(b,first[a]);
	first[a] = nume++;
}
int mxdep[maxn],wson[maxn],sz[maxn];
int dfn[maxn],dfx[maxn],n,k;
int dp_array[maxn];
int *f[maxn];
void init(int u,int fa){
	mxdep[u] = 0;wson[u] = 0;sz[u] = 1;
	for(int e=first[u];~e;e=edge[e].nxt){
		int v=edge[e].to;
		if(v == fa) continue;
		init(v,u);
		mxdep[u] = max(mxdep[u],mxdep[v] + 1);
		sz[u] += sz[v];
		if(!wson[u] || mxdep[v] > mxdep[wson[u]])
			wson[u] = v;
	}
}
void pre(int u,int fa){
	dfx[dfn[u] = ++*dfn] = u;
	f[u] = dp_array + dfn[u];
	if(wson[u]) pre(wson[u],u);
	for(int e=first[u];~e;e=edge[e].nxt){
		int v=edge[e].to;
		if(v==fa || v==wson[u]) continue;
		pre(v,u);
	}
}
int g[maxn],h[maxn],ans;
void dfs(int u,int fa){
	if(wson[u]) dfs(wson[u],u);
	f[u][0] = wson[u] ? sz[wson[u]] : 0;
	int m = min(k,mxdep[u]);
	for(int e=first[u];~e;e=edge[e].nxt){
		int v = edge[e].to;
		if(v==wson[u] || v==fa) continue;
		dfs(v,u);
		int len = min(k,mxdep[v] + 1);
		g[0] = sz[v];Rep(i,1,len) g[i] = f[v][i-1];
		Rep(i,0,len) h[i] = f[u][i];
		Rep(i,0,len)
			f[u][i] = min(g[i]+h[min(i,k-i)],g[min(i,k-i)] + h[i]);
		Rep(i,0,len) if(k-i>len && k-i<=m) f[u][k-i] += g[i];
		Rep(i,len+1,k-len-1) if(i<=m) f[u][i] += g[len];
		Rep(i,1,m) f[u][i] = min(f[u][i],f[u][i-1]);
	}
	ans = min(ans,n - sz[u] + f[u][min(k,m)]);
}
void solve(){
    mem(first,-1);nume = 0;
	n = read();k = read();ans = n;
    Rep(i, 1, n) {
        dfx[i] = dfn[i] = dp_array[i] = 0;
    }
	rep(i,1,n) {
		int x = read(),y = read();
		Addedge(x,y);
		Addedge(y,x);
	} init(1,0);
	*dfn = 0;
	pre(1,0);
	dfs(1,0);
	writeln(ans);
}
int main(){
	int T = 1; //cin>>T;
    while(T--){
        solve();
    }
	return 0;
}
/*
2
10 3
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
7 2
1 2
2 3
1 4
4 5
1 6
6 7
*/

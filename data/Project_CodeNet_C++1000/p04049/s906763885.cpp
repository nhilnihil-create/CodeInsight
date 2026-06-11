/*
 * @Description: 
 * @Version: 1.0
 * @Autor: goatzyq
 * @Date: 2020-08-20 12:07:17
 * @LastEditors: goatzyq
 * @LastEditTime: 2020-08-20 15:13:07
 */
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using db = double;
using vi = vector<int>;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi head
#define se second
#define SZ(x) ((int)(x).size())
#define debug(x) cout << #x <<'	' << x <<endl
const int inf = 0x3f3f3f3f;
const db eps = 1e-8;
const int mod = 1e9+7;
ll qpow(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b&1)ret = ret*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return ret;
}

const int maxn = 3e5+100;
struct Edge{
	int to,nxt;
	Edge(){}
	Edge(int to,int nxt):to(to),nxt(nxt){}
}edge[maxn*2];
int head[maxn],num;
void addedge(int a,int b){
	edge[num] = Edge(b,head[a]);
	head[a] = num++;
}

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char getcha() {
    if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }
    return *ci++;
}
inline int getint() {
    int A = 0;
    if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
    else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
    return A;
}
int mxdep[maxn],son[maxn],sz[maxn];
int dfn[maxn],dfx[maxn],n,k;
int dp[maxn];
int *f[maxn];
void init(int u,int fa){
	mxdep[u] = 0;son[u] = 0;sz[u] = 1;
	for(int e=head[u];~e;e=edge[e].nxt){
		int v=edge[e].to;
		if(v == fa) continue;
		init(v,u);
		mxdep[u] = max(mxdep[u],mxdep[v] + 1);
		sz[u] += sz[v];
		if(!son[u] || mxdep[v] > mxdep[son[u]])
			son[u] = v;
	}
}
void pre(int u,int fa){
	dfx[dfn[u] = ++*dfn] = u;
	f[u] = dp + dfn[u];
	if(son[u]) pre(son[u],u);
	for(int e=head[u];~e;e=edge[e].nxt){
		int v=edge[e].to;
		if(v==fa || v==son[u]) continue;
		pre(v,u);
	}
}
int g[maxn],h[maxn],ans;
void dfs(int u,int fa){
	if(son[u]) dfs(son[u],u);
	f[u][0] = son[u] ? sz[son[u]] : 0;
	int m = min(k,mxdep[u]);
	for(int e=head[u];~e;e=edge[e].nxt){
		int v = edge[e].to;
		if(v==son[u] || v==fa) continue;
		dfs(v,u);
		int len = min(k,mxdep[v] + 1);
		g[0] = sz[v];
		rep(i,1,len+1) g[i] = f[v][i-1];
		rep(i,0,len+1) h[i] = f[u][i];
		rep(i,0,len+1)
			f[u][i] = min(g[i]+h[min(i,k-i)],g[min(i,k-i)] + h[i]);	
		rep(i,0,len+1) if(k-i>len && k-i<=m) f[u][k-i] += g[i];
		rep(i,len+1,k-len) if(i<=m) f[u][i] += g[len];
		rep(i,1,m+1) f[u][i] = min(f[u][i],f[u][i-1]);
	}
	ans = min(ans,n - sz[u] + f[u][min(k,m)]);
}
void solve(){
	memset(head,-1, sizeof(head));num = 0;
	n = getint();k = getint();ans = n;
	rep(i,1,n) {
		int x = getint(),y = getint();
		addedge(x,y);
		addedge(y,x);
	} 	
	init(1,0);
	*dfn = 0;
	pre(1,0);
	dfs(1,0);
	printf("%d\n", ans);
}
int main(){
//	freopen("in.txt", "r", stdin);
	// int t;
	// t = getint();while(t--)
    solve();
	return 0;
}
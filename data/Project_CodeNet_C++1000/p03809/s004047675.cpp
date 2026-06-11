#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const LL N = 1000000007;

LL ec = 0,hed[200005] = {0},nxt[400005],to[400005];
void add_edge(LL f,LL t){
	++ ec; to[ec] = t; nxt[ec] = hed[f]; hed[f] = ec;
}

LL n,flg,a[200005];
LL deg[200005] = {0},siz[200005],mx[200005];

void dfs(LL u,LL f){
	for(LL i = hed[u];i;i = nxt[i]){
		LL v = to[i];
		if(v == f) continue;
		dfs(v,u);
		mx[u] = max(mx[u],mx[v]);
		siz[u] += siz[v];
	}
	if(deg[u] == 1){
		siz[u] = a[u];
		mx[u] = a[u];
	}
	else{
		LL del = siz[u] - a[u],mxd;
		mxd = (mx[u] * 2 > siz[u] ? siz[u] - mx[u] : (siz[u] >> 1));
		if(del < 0 || del > mxd) flg = 0;
		siz[u] -= (del << 1); mx[u] = siz[u];
	}
}

int main(){
	ios::sync_with_stdio(false);
	LL u,v;
	cin >> n;
	for(LL i = 1;i <= n;i ++) cin >> a[i];
	for(LL i = 1;i < n;i ++){
		cin >> u >> v;
		add_edge(u,v); add_edge(v,u);
		deg[u] ++; deg[v] ++;
	}
	
	if(n == 2){
		if(a[1] == a[2]) cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}
	
	LL rt = 1; for(LL i = 1;i <= n;i ++) if(deg[i] != 1) rt = i;
	add_edge(n + 1,rt); a[n + 1] = 0;
	flg = 1; dfs(n + 1,0);
	cout << (flg ? "YES" : "NO") << endl;
	return 0;
}
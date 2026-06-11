#include <bits/stdc++.h>
using namespace std;
const int maxn = 123456;
vector<int> e[maxn];
int vis[maxn], cor[maxn];
int sz, ok;
void dfs(int u, int v, int d = 0){
	vis[u] = 1;
	sz++;
	cor[u] = d;
	for(int nxt : e[u]){
		if(!vis[nxt]){
			dfs(nxt, u, d ^ 1);
		} else {
			if(cor[nxt] != (d^1)){
				ok = 0;
			}
		}
	}
}
int main(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int lone = 0, by = 0, no = 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			sz = 0;
			ok = 1;
			dfs(i, 0, 0);
			if(sz == 1) lone++;
			else if(ok) by++;
			else no++;
		}
	}
	long long ans = 0;
	ans += 2ll * lone * (n - lone);
	ans += 1ll * lone * lone;
	ans += 1ll * no * no;
	ans += 2ll * no * by;
	ans += 2ll * by * by;
	cout << ans << endl;
	return 0;
}

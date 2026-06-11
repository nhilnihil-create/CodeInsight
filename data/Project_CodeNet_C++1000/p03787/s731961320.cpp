#include <bits/stdc++.h>

#define MAXN (100010)
#define ll long long

int n, m;
std::vector<int> vec[MAXN];
int col[MAXN];
bool vis[MAXN];
int non_bi;

void dfs(int u, int c){
	col[u] = c;
	vis[u] = 1;
	for(int v : vec[u]){
		if(vis[v]){
			if(col[v] != (c ^ 1)) non_bi = 1;
			continue;
		}
		dfs(v, c ^ 1);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++ i){
		int u, v;
		scanf("%d%d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	ll n1 = 0, n2 = 0, a = 0;
	for(int i = 1; i <= n; ++ i){
		if(!vis[i]){
			if(vec[i].empty()){
			    a ++;
			    continue;
			}
			non_bi = 0;
			dfs(i, 0);
			if(non_bi){
				n2 ++;
			}
			else{
				n1 ++;
			}
		}
	}
	ll ans = (2ll) * a * n - a * a + n1 * n1 * 2 + n2 * n2 + n1 * n2 * 2;
	std::cout << ans << std::endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a[100010];
int ans = 0;
int depth[100010];
void dfs(int u, int p){
	if(a[u].empty()){
		depth[u] = 0;
	} else{
		for(int v : a[u]){
			dfs(v, u);
			depth[u] = max(depth[u], depth[v] + 1);
		}
	}
	if(depth[u] == k - 1){
		if(u == 1) return;
		if(p != 1) ans++;
		depth[u] = -1;
	}
}
int main(){
	// freopen("in.in","r",stdin);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		if(i == 1 && x != 1) ans++;
		if(i > 1){
			a[x].push_back(i);
		}
	}
	dfs(1, 0);
	cout << ans << "\n";
}
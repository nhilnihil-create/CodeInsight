#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::cin;

std::vector<std::vector<int>> g;
std::vector<int> dp;
int n;

int dfs(int v, int p = -1){
	if(~dp[v]) return dp[v];
	
	int ret = 0;
	for(auto e : g[v]){
		if(e == p) continue;
		ret ^= dfs(e, v) + 1;
	}
	
	return dp[v] = ret;
}

int main(){
	cin >> n; g.resize(n); dp.resize(n, -1);
	for(int i = 0; i < n - 1; i++){
		int a, b; cin >> a >> b;
		
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	
	if(dfs(0)) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	return 0;
}

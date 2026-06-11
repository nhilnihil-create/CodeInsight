#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int N = 2005;
int n, k, ans;
vector <int> g[N];
bool used[N];

int dfs(int v, int deep){
	int cnt = 1;
	used[v] = 1;
	for(auto to : g[v]){
		if(!used[to] && deep + 1 <= k / 2)
			cnt += dfs(to, deep + 1);
	}
	return cnt;
}

int main(){
	cin >> n >> k;
	for(int i = 1; i < n; ++i){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	for(int i = 1; i <= n; ++i){
		memset(used, 0, sizeof used);
		ans = max(ans, dfs(i, 0));
	}
	if(k & 1){
	for(int i = 1; i <= n; ++i){
		for(auto j : g[i]){
			memset(used, 0, sizeof used);
			used[j] = used[i] = 1;
			ans = max(ans, dfs(i, 0) + dfs(j, 0));
		}
	}
	}
	
	cout << n - ans;
	
	return 0;
}
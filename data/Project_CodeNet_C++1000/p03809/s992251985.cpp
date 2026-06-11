#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

int n,a[100000],child[100000];
vector<int> G[100000];
bool flag = true;

int dfs(int v,int par){
	if(G[v].size() == 1) return a[v];
	int sum = 0,ma = 0;
	for(int i = 0;i < G[v].size();i++){
		int to = G[v][i];
		if(par == to) continue;
		int ans = dfs(to,v);
		if(ans < 0) return -1;
		sum += ans;
		ma = max(ma,ans);
	}
	if(sum - a[v] < 0 || min(sum - ma,sum / 2) < sum - a[v] || a[v] * 2 - sum < 0) {
		flag = false;
		return -1;
	}
	return a[v] * 2 - sum;
}

signed main(){
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i < n - 1;i++){
		int u,v;
		cin >> u >> v;u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(n == 2){
		if(a[0] == a[1]) cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}
	int v = 0;
	while(G[v].size() == 1) v++;
	if(dfs(v,-1)) flag = false;
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
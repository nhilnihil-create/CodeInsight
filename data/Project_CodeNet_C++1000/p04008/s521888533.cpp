#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int a[100005], dp[100005];
vector<int> g[100005];
int n, k;
int ans = 0;
int dfs(int u){
	int d = 0;
	for(int i=0;i<g[u].size();i++){
		int v = g[u][i];
		int x = dfs(v);
		d = max(d, x);
	}
	if(d == k-1 && a[u] != 1){
		ans++;
		d = -1;
	}
	return d+1;
}
int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		if(i == 1) continue;
		g[a[i]].push_back(i);
	}
	queue<int> q;
	q.push(1);
	dp[1] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v = g[u][i];
			if(dp[v] == -1){
				dp[v] = dp[u]+1;
				q.push(v);
			}
		}
	}
	bool ok = 1;
	int cycle = dp[a[1]]+1;
	dp[1] = cycle;
	for(int i=1;i<=n;i++){
		if(dp[i] > k){
			ok = 0;
			break;
		}
		if( (k-dp[i])%cycle  == 0) continue;
		ok = 0;
		break;
	}
	if(ok){
		printf("0\n");
		return 0;
	}
	for(int i=0;i<g[a[1]].size();i++){
		if(g[a[1]][i] == 1){
			g[a[1]].erase(g[a[1]].begin()+i);
			break;
		}
	}
	if(a[1] != 1) a[1] = 1, ans++;
	dfs(1);
	printf("%d\n", ans);
}
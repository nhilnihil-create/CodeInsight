#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

llint n, d;
vector<llint> G[2005];
llint dist[2005];

void dfs(int v, int p, llint d)
{
	dist[v] = min(dist[v], d);
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v, d+1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> d;
	llint u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	llint ans = inf;
	for(int i = 1; i <= n; i++){
		
		if(d % 2 == 0){
			llint cnt = 0;
			for(int j = 1; j <= n; j++) dist[j] = inf;
			dfs(i, -1, 0);
			for(int j = 1; j <= n; j++){
				if(dist[j] > d/2) cnt++;
			}
			ans = min(ans, cnt);
		}
		else{
			for(int j = 0; j < G[i].size(); j++){
				llint cnt = 0;
				for(int k = 1; k <= n; k++) dist[k] = inf;
				dfs(i, G[i][j], 0);
				dfs(G[i][j], i, 0);
				for(int k = 1; k <= n; k++){
					if(dist[k] > d/2) cnt++;
				}
				ans = min(ans, cnt);
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
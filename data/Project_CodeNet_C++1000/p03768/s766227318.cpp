#include <bits/stdc++.h> 

using namespace std; 

const int MAX_N = 100005; 
const int MAX_D = 15; 

int dp[MAX_N][MAX_D]; 
int c[MAX_N]; 
vector <int> adj[MAX_N]; 
int n, m, query; 

int main () {
//	freopen("input.txt", "r", stdin); 
	//freopen("output.txt", "w", stdout); 
	scanf("%d %d", &n, &m); 
	for (int i = 1; i <= m; i++) {
		int u, v; 
		scanf("%d %d", &u, &v); 
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	scanf("%d", &query); 
	for (int i = 1; i <= query; i++) {
		int u, d; 
		scanf("%d %d %d", &u, &d, &c[i]); 
		dp[u][d] = i; 
	}

	for (int i = 1; i <= n; i++) {
		adj[i].push_back(i); 
	}

	for (int d = 9; d >= 0; d--) {
		for (int u = 1; u <= n; u++) {
			for (int i = 0; i < (int) adj[u].size(); i++) {
				int v = adj[u][i]; 
				dp[v][d] = max(dp[v][d], dp[u][d + 1]); 
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int ans = 0; 
		for (int d = 0; d <= 9; d++) {
			ans = max(ans, dp[i][d]); 
		}

		printf("%d\n", c[ans]); 
	}
	return 0; 
}
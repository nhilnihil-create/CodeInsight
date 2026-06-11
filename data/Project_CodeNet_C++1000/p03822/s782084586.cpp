#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int a[N];
int dp[N];

vector <int> adj[N];


int dfs(int a) {

	for (int u: adj[a]) {
		dfs(u);
	}
	vector <int> v;
	if(adj[a].size() == 0) return dp[a] = 0;
	for (int u: adj[a]) {
		v.push_back(dp[u]);
	}

	sort(v.begin(),v.end());
	reverse(v.begin(), v.end());
	dp[a] = 0;
	for (int i = 0; i < adj[a].size(); ++i) {
		dp[a] = max(dp[a],v[i]+i+1);
	}
	return dp[a];

}


int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; ++i) {
		cin >> a[i];
		a[i]--;
		adj[a[i]].push_back(i);
	}

	printf("%d\n",dfs(0));


	
}
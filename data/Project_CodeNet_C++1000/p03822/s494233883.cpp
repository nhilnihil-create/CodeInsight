#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<int> G[100010];
int dp[100010];

int dfs(int v){
	if(dp[v] != INF) return dp[v];
	vector<int> arr;
	dp[v] = G[v].size();
	for(int i=0; i<G[v].size(); i++){
		arr.push_back(dfs(G[v][i]));
	}
	sort(arr.begin(), arr.end());
	for(int i=0; i<arr.size(); i++){
		if(dp[v] < arr[i] + arr.size() - i){
			dp[v] = arr[i] + arr.size() - i;
		}
	}
	return dp[v];
}

int main(){
	int N; cin >> N;
	for(int i=1; i<N; i++){
		int a; cin >> a; a--;
		G[a].push_back(i);
	}
	fill(dp, dp+N, INF);
	cout << dfs(0) << "\n";
	return 0;
}
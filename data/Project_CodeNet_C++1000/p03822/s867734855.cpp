#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n;

vector<int> lose[100005];
vector<int> sizes[100005];
int dp[100005];

void dfs(int id){
	int len = lose[id].size();
	dp[id] = len + 1;
	for(auto to: lose[id]){
		dfs(to);
		sizes[id].push_back(dp[to]);
	}
	sort(sizes[id].begin(), sizes[id].end());
	for(int i = 0; i < len; i++){
		dp[id] = max(dp[id], sizes[id][i] + len - i);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		int x;
		scanf("%d", &x);
		lose[x].push_back(i);
	}
	dfs(1);
	printf("%d\n", dp[1] - 1);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

vector<int> tree[maxn];

int dp[maxn];

int n = 0;

void dfs(int u) {
	vector<int> vec;
	for (int i = 0; i < tree[u].size(); i++) {
		int v = tree[u][i];
		dfs(v);
		vec.push_back(dp[v]);
	}
	int sz = int (vec.size());
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		dp[u] = max(dp[u], vec[i] + sz - i);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p = 0; scanf("%d", &p);
		tree[p].push_back(i);
	}
	dfs(1);
	printf("%d\n", dp[1]);
	return 0;
}
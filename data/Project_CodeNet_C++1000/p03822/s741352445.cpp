#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n, a;
vector < int > g[maxn];

int dfs (int u) {
	int res = 0;
	vector < int > prior;
	for (int v: g[u]) 
		prior.push_back(dfs(v));
	sort(prior.rbegin(), prior.rend());
	if (prior.empty())
		return res;
	else {
		for (int i = 0; i < int(prior.size()); ++i)
			prior[i] += i + 1, res = max(res, prior[i]);
		return res;
	}
}

signed main () {
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &a);
		g[a].push_back(i);
	}
	printf("%d\n", dfs(1));
}

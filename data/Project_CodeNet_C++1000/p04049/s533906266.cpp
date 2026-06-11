#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> adj[2020];
vector<int> v;
int dep[2020];

void dfs(int now, int par) {
	v.push_back(now);
	dep[now] = dep[par] + 1;
	for(int i : adj[now]) {
		if(i == par) continue;
		dfs(i, now);
	}
}

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int ans = 0;

	for(int i = 1; i <= N; i++) {
		dep[i] = 0;
		int mx = 0, sum = 1;
		for(int j : adj[i]) {
			dfs(j, i);
			int n1 = 0, n2 = 0;
			while(v.size()) {
				if(dep[v.back()] <= K / 2) n1++;
				if((K & 1) && dep[v.back()] == (K + 1) / 2) n2++;
				v.pop_back();
			}
			sum += n1;
			mx = max(mx, n2);
		}
		ans = max(ans, sum + mx);
	}
	printf("%d\n", N - ans);
	return 0;
}
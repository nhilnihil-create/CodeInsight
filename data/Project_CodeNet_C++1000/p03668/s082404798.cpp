#include <bits/stdc++.h>
using namespace std;
bool seen[100010];
vector<int> adj[100010];
int n;
int dfs(int a)
{
	seen[a] = 1;
	int winner = 0;
	for (auto b : adj[a])
	{
		if (!seen[b]) winner ^= (dfs(b)+1);
	}
	return winner;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int res = dfs(1);
	if (res) printf("Alice\n");
	else printf("Bob\n");
}
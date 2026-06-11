#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n;
vector<int> graph[500000];
int x[500000];
int dfs(int v)
{
	x[v] = 1;
	int c = 0, f = 0;
	for (auto u : graph[v])
	{
		if (x[u] == 0)
		{
			f ^= (dfs(u) + 1);
			c++;
		}
	}
	return f;
}

int main()
{
	cin >> n;
	for (int i = 0; i + 1 < n; i++) {
		int v, u;
		cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}
	if (dfs(1)) cout << "Alice";
	else cout << "Bob";
}

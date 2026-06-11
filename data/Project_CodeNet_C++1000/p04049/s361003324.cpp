#include<bits/stdc++.h>

#define MOD 1000000007
#define MODSET(d) if ((d) >= MOD) d %= MOD;

using namespace std;

vector<int> graph[4000];
bool visited[4000];
int subtreeSize[4000];
int n, k;

int dfsTree(int u, int distance, bool isRoot)
{
	visited[u] = true;
	subtreeSize[u] = 1;
	
	if (distance == (k+1)/2)
	{
		return 1;
	}
	
	int total = 0;
	int maxK = 0;
	
	for (auto v: graph[u])
	{
		if (!visited[v])
		{
			int curr = dfsTree(v, distance + 1, false);
			total += curr;
			maxK = max(maxK, curr);
			subtreeSize[u] += subtreeSize[v];
		}
	}
	
	if (isRoot)
	{
		return n - (subtreeSize[u] - (k % 2 ? (total - maxK) : 0));
	}
	else
	{
		return total;
	}
}

int main()
{
    #ifdef VSP4
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	int i, j, u, v, ans;
	
	cin >> n >> k;
	
	for (i = 0; i < n-1; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	ans = n;
	
	for (i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));
		memset(subtreeSize, 0, sizeof(subtreeSize));
		ans = min(ans, dfsTree(i, 0, true));
	}
	
	cout << ans;
		
    return 0;
}
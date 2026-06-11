#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>

using namespace std;

const int N = 100 * 1000 + 5;

vector <int> graph[N];
int vertices[N];
int dist[N];
int color[N];
int dp[N][12];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) 
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) 
	{
		cin >> vertices[i] >> dist[i] >> color[i];
		dp[vertices[i]][dist[i]] = max(dp[vertices[i]][dist[i]], i);
	}
	for (int j = 9; j >= 0; j--) 
	{
		for (int i = 1; i <= n; i++) 
		{
			dp[i][j] = max(dp[i][j + 1], dp[i][j]);
			for (int k = 0; k < graph[i].size(); k++) 
			{
				int u = graph[i][k];
				dp[i][j] = max(dp[i][j], dp[u][j + 1]);
			}
		}
	}
	for (int i = 1; i <= n; i++) 
	{
		cout << color[dp[i][0]] << endl;
	}
}

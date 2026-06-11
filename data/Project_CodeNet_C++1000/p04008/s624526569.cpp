//#include<bits/stdc++.h>
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

const int N = 1e5 + 5;
vector<int> graph[N];
int dp[N];
int a[N];
int h[N];
int g[N];
int p;
bool mark[N];
int n, k; 
int ans;

void dfs(int v, int par)
{
	mark[v] = true;
	dp[v] = 1;
	for (int i = 0; i < graph[v].size(); i++)
	{
		int u = graph[v][i];
		if (!mark[u])
		{
			dfs(u, v);
			dp[v] = max(dp[v], dp[u] + 1);
		}
	}
	if (dp[v] == k && par != 0)
	{
		ans++;
		dp[v] = 0;
	}
}

int main() 
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		a[i] = v;
		v--;
		graph[v].push_back(i);
	}
	if (a[0] != 1)
	{
		ans++;
		a[0] = 1;
	}
	dfs(0, 0);
	cout << ans << endl;




}


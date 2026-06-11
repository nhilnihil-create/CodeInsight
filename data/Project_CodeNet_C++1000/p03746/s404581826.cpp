//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include<iomanip>
 
using namespace std;

const int N = 1e5 + 5;
vector<int> graph[N];
vector<int> path;
vector<int> path2;
bool mark[N];
bool check = true;
int n, m;

void dfs1(int v)
{
	if (!check)
	{
		return;
	}
	mark[v] = true;
	path.push_back(v);
	for (int i = 0; i < graph[v].size(); i++)
	{
		int u = graph[v][i];
		if (!mark[u])
		{
			dfs1(u);
		}
	}
	check = false;
}

void dfs2(int v)
{
	mark[v] = true;
	if (!check)
	{
		return;
	}
	path2.push_back(v);
	for (int i = 0; i < graph[v].size(); i++)
	{
		int u = graph[v][i];
		if (!mark[u])
		{
			dfs2(u);
		}
	}
	check = false;
}

int main() 
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}
	mark[0] = true;
	int cnt = 0;
	for (int i = 0; i < graph[0].size(); i++)
	{
		int u = graph[0][i];
		if (!mark[u] && cnt == 1)
		{
			check = true;
			dfs2(u);
			cnt++;
		}
		if (!mark[u] && cnt == 0)
		{
			check = true;
			dfs1(u);
			cnt++;
		}
		if (cnt == 2)
		{
			break;
		}
	}
	cout << path.size() + path2.size() + 1 << endl;
	reverse(path2.begin(), path2.end());
	for (int i = 0; i < path2.size(); i++)
	{
		cout << path2[i] + 1 << " ";
	}
	cout << 1 << " ";
	for (int i = 0; i < path.size(); i++)
	{
		cout << path[i] + 1 << " ";
	}


}

 
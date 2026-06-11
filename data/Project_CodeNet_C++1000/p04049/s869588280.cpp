#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

const int MAXN = 2 * 1000 + 10;
vector <int> adj[MAXN];
int h[MAXN];
bool visit[MAXN];
int adj1[MAXN];
int adj2[MAXN];
int ans[MAXN];
int n, k;

void dfs(int v)
{
	visit[v] = true;
	for(int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if(!visit[u])
		{
			h[u] = (h[v] + 1);
			dfs(u);
		}
	}
	return;
}

void strt()
{
	for(int i = 0; i < n; i++)
	{
		visit[i] = false;
		h[i] = 0;
	}
	return;
}

void dfsall()
{
	if(k % 2 == 0)
	{
		for(int i = 0; i < n; i++)
		{
			strt();
			dfs(i);
			int cnt = 0;
			for(int j = 0; j < n; j++)
			{
				if(h[j] > (k / 2))
					cnt++;
			}
			ans[i] = cnt;		
		}
	}
	else
	{
		for(int i = 0; i < n - 1; i++)
		{
			strt();
			int v = adj1[i], u = adj2[i];
			visit[u] = true;
			dfs(v);
			dfs(u);
			int cnt = 0;
			for(int j = 0; j < n; j++)
			{
				if(h[j] > (k / 2))
					cnt++;
			}
			ans[i] = cnt;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		adj1[i] = a;
		adj2[i] = b;
		ans[i] = 0;
	}
	ans[n - 1] = 0;
	dfsall();
	int mn = INT_MAX;
	for(int i = 0; i < n - 1; i++)
		mn = min(mn, ans[i]);
	if(k % 2 == 0)
		mn = min(mn, ans[n - 1]);
	cout << mn << endl;
	return 0;
}


#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define f first
#define s second 

const int MAXN = 1000 * 1000 + 10;

vector<int> adj[MAXN];
bool mark[MAXN];
int h[MAXN];
pair<int, int> e[MAXN];


ll mod = 1000*1000*1000+7;

void addEdge(int x, int y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}

void dfs(int u, int v = 0)
{
	mark[u] = true;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int x = adj[u][i];
		if(!mark[x])
		{
			h[x] = h[u]+1;
			dfs(x);
		}
	}
	return;
	
}

void cl(int n)
{
	for(int i = 1; i <= n; i++)
	{
		mark[i] = false;
		h[i] = 0;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n-1; i++)
	{
		int x, y;
		cin >> x >> y;
		addEdge(x, y);
		e[i] = {x, y};
	}
	int ans = n;
	if(k%2 == 0)
	{
		for(int i = 1; i <= n; i++)
		{
			cl(n);
			dfs(i);
			int cnt = 0;
			for(int j = 1; j <= n; j++)
			{	
				if(h[j] > k/2)
					cnt++;
			}
			ans = min(ans, cnt);
		}
	}
	else
	{
		for(int i = 0; i < n-1; i++)
		{
			cl(n);
			int x = e[i].f;
			int y = e[i].s;
			mark[x] = true;
			mark[y] = true;
			dfs(x);
			dfs(y);
			int cnt = 0;
			for(int j = 1; j <= n; j++)
			{	
				if(h[j] > k/2)
					cnt++;
			}
			ans = min(ans, cnt);
			
		}	
	}
	cout << ans << endl;
		
	


	return 0;
}

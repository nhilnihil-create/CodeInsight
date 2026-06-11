#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const long long inf = 1e15;
const int mod = 1e6;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
 
const long long N = 4000 * 100 + 10;

vector <int> adj[N];
ll dist[2][N];
vector <pii> edge;
ll n, k;

void bfs(int src , int t)
{
	for (int i = 0; i < n; i++)
	{
		dist[t][i] = inf;
	}
	dist[t][src] = 0;
	queue <int> q;
	q.push(src);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++)
		{
			int u = adj[v][i];
			if(dist[t][u] > dist[t][v] + 1)
			{
				dist[t][u] = dist[t][v] + 1;
				q.push(u);
			}
		}
	}
}
int main()
{
	faster();
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		cin >> v >> u;
		v--;
		u--;
		adj[v].push_back(u);
		adj[u].push_back(v);
		edge.push_back({u, v});
	}
	ll ans = inf;
	if(k % 2 == 0)
	{
		k /= 2;
		for (int i = 0; i < n; i++)
		{
			bfs(i , 0);
			ll cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if(dist[0][j] > k)
					cnt++;
			}
			ans = min(cnt, ans);
		}
		cout << ans << endl;	
		return 0;
	}
	for (int i = 0; i < edge.size(); i++)
	{
		ll cnt = 0;
		int v = edge[i].first;
		int u = edge[i].second;
		bfs(v, 0);
		bfs(u, 1);
		for (int j = 0; j < n; j++)
		{
			if(max(dist[0][j], dist[1][j]) <= (k - 1) / 2)
			{
				continue;
			}
			else
			{
				if(max(dist[0][j], dist[1][j]) == (k + 1) / 2)
				{
					if(abs(dist[0][j] - dist[1][j]) > 1)
						cnt++;
				}
				else
					cnt++;
			}
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}
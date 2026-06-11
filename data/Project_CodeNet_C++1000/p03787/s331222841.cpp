#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;

const long long INF = 1e18; 
const int mod = 1e9 + 7;//200003;786433;998244353;
const double Pi = acos(-1);
  
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n, m;
int Color[100005];
vector <int> Adj[100005];
long long cnt, bi, nbi;

signed main()
{
	Fastio();
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		Color[i] = -1;
	}
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		Adj[u].eb(v);
		Adj[v].eb(u);
	}
	for(int i = 1; i <= n; i++)
	{
		if(Adj[i].size() == 0)
		{
			cnt++;
			continue;
		}
		if(Color[i] != -1)
		{
			continue;
		}
		queue <int> BFS;
		BFS.push(i);
		Color[i] = 0;
		bool ok = true;
		while(BFS.empty() == false)
		{
			int node = BFS.front();
			BFS.pop();
			for(auto x : Adj[node])
			{
				if(Color[x] == -1)
				{
					Color[x] = Color[node] ^ 1;
					BFS.push(x);
				}
				else
				{
					if(Color[x] == Color[node])
					{
						ok = false;
					}
				}
			}
		}
		if(ok)
		{
			bi++;
		}
		else
		{
			nbi++;
		}
	}
	cout << cnt * cnt + cnt * (n - cnt) * 2 + bi * bi * 2 + 2 * bi * nbi + nbi * nbi;
}
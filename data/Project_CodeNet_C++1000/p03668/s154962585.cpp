#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;

const long long INF = 1e18; 
const int mod = 200003;//1e9 + 7;//786433;//998244353;//1e9 + 7
const double Pi = acos(-1);
  
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
int g[100005];
vector <int> Adj[100005];

void DFS(int node, int p = -1)
{
	for(auto x : Adj[node])
	{
		if(x == p)
		{
			continue;
		}
		DFS(x, node);
		g[node] ^= (g[x] + 1);
	}
}

signed main()
{
	Fastio();
	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		Adj[u].eb(v);
		Adj[v].eb(u);
	}
	DFS(1);
	if(g[1])
	{
		cout << "Alice";
	}
	else
	{
		cout << "Bob";
	}
}
//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()
#define pb push_back

#define error(x) cout << #x << " = " << x << endl

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int N = 1e5 + 20, D = 10 + 2;
int n, m, q;
int col[D][N];
int v[N], d[N], c[N];
vector <int> g[N];



int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 0, u, v; i < m; i++)
	{
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}

	cin >> q;

	for (int i = 0; i < q; i++)
	{
		cin >> v[i] >> d[i] >> c[i];
		v[i]--;
	}

	for (int i = q - 1; i >= 0; i--)
	{
		queue <pii> que;
		
		for (int j = d[i]; j >= 0; j--)
		{
			if (!col[j][v[i]])
			{
				col[j][v[i]] = c[i];
				que.push({j, v[i]});
			}
		}

		while (_sz(que))
		{
			int d = que.front().F, v = que.front().S;

			que.pop();

			if (!d) continue ;
			
			for (int u : g[v])
				if (!col[d - 1][u])
				{
					col[d - 1][u] = col[d][v];
					que.push({d - 1, u});
				}
		}
	}

	for (int i = 0; i < n; i ++) 
	{
		cout << col[0][i] << '\n'; 
	}
}

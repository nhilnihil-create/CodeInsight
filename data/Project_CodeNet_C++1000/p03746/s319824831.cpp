//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

const int N = (int)1e5 + 228;

using namespace std;

int n, m, a[N], b[N];
bool used[N], was[N];
vector < pair < int, int > > g[N];

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	forn(i, m)
	{
		scanf("%d%d", &a[i], &b[i]);
		g[a[i]].pb({b[i], i});
		g[b[i]].pb({a[i], i});
	}
	used[1] = true;
	int v = a[1], u = b[1];
	was[v] = was[u] = true;
	deque < int > dq;
	dq.pb(v);
	dq.pb(u);
	while(true)
	{
		int vv = v, uu = u;
		for (auto e : g[v])
		{
			int to = e.first, id = e.second;
			if (!used[id])
			{	
				if (!was[to])
				{
					was[to] = true;
					v = to;
					used[id] = true;
				    dq.push_front(to);
					break;	
				}					
			}
		}
		for (auto e : g[u])
		{	
			int to = e.first, id = e.second;
			if (!used[id])
			{
				if (!was[to])
				{
					was[to] = true;
					u = to;
					used[id] = true;
					dq.pb(to);
					break;
				}
			}
		}
		if (vv == v && uu == u)
			break;
	}
	printf("%d\n", (int)dq.size());
	for (auto it : dq)
		printf("%d ", it);

	return 0;
}


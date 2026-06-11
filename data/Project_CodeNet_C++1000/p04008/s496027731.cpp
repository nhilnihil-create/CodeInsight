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

int n, k, depth[N], a[N], ans;
vector < int > g[N];

void dfs(int v, int pr)
{
	for (auto to : g[v])
	{
		if (to == pr)
			continue;
		dfs(to, v);
		if (v != 1 && depth[to] + 1 == k)
		{
			ans++;
		}
		else
			depth[v] = max(depth[v], depth[to] + 1);
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	//~read
	scanf("%d%d", &n, &k);
	forn(i, n)
		scanf("%d", &a[i]);
	//~solve
	if (a[1] != 1)
		ans++;
	for (int i = 2; i <= n; i++)
		g[a[i]].pb(i);
	dfs(1, -1);
	cout << ans << endl;

	return 0;
}


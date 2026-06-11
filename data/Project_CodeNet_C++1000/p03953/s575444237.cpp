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
const int LOG = 60;
 
using namespace std;
 
int n, m, up[LOG][N], p[N];
ll d[N], x[N], k, res[N];
 
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		
 
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
 
	//~read
	scanf("%d", &n);
	forn(i, n)
		scanf("%lld", &x[i]);
	forn(i, n - 1)
		d[i] = x[i + 1] - x[i];
	//~solve
	forn(i, n - 1)
		p[i] = i;
	scanf("%d%lld", &m, &k);
	forn(i, m)	
	{
		int id;
		scanf("%d", &id);
		swap(p[id - 1], p[id]);
	}
	//~precalc
	forn(i, n - 1)
		up[0][p[i]] = i;
	for (int i = 1; i < LOG; i++)
	{
		forn(j, n - 1)
		{
			up[i][j] = up[i - 1][up[i - 1][j]];
		}
	}
	forn(i, n - 1)
	{	
		int v = i;
		for (int j = LOG - 1; j >= 0; j--)
		{
			if (k & (1ll << j))
				v = up[j][v];
		}
		res[v] = d[i];
	}                 
	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
			x[i] = x[i - 1] + res[i - 1];
		printf("%lld\n", x[i]);
	}
		
 
	return 0;
}
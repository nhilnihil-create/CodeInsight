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

int n, ans[N];
vector < int > g[N];

void dfs(int v)
{
	vector < int > t;
	t.pb(0);
	for (auto to : g[v])
	{
		dfs(to);
		t.pb(ans[to] + 1);
	}
	sort(all(t));
	for (int i = 0; i < (int)t.size(); i++)
	{
		ans[v] = max(ans[v], t[i] + (int)g[v].size() - i);
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		int j;
		scanf("%d", &j);
		g[j].pb(i);
	}             
	dfs(1);
	cout << ans[1] << endl;

	return 0;
}


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 1e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n;
ll a[maxn], dp[maxn];
vector<int> graph[maxn];

void dfs(int u, int prev)
{
	if (prev != -1 && graph[u].size() == 1)
	{
		dp[u] = a[u];
		//cerr << '@' << u << ' ' << dp[u] << endl;
		return;
	}
	for (int i : graph[u])
		if (i != prev)
			dfs(i, u);

	ll sum = 0;
	for (int i : graph[u])
		if (i != prev)
			sum += dp[i];
	ll count = sum - a[u];
	ll checker = a[u] - count, mx = a[u] - count;
	for (int i : graph[u])
		if (i != prev)
			checker += dp[i], mx = max(mx, dp[i]);
	if (a[u] - count < 0)
	{
		cout << "NO" << endl;
		exit(0);
	}
	if ((checker & 1) || mx > checker / 2)
	{
		cout << "NO" << endl;
		exit(0);
	}
	dp[u] = a[u] - count;
	//cerr << '@' << u << ' ' << dp[u] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[--u].pb(--v);
		graph[v].pb(u);
	}
	int root = -1;
	for (int i = 0; i < n; i++)
		if (graph[i].size() > 1)
		{
			root = i;
			break;
		}

	if (root == -1)
	{
		cout << (a[0] == a[1] ? "YES" : "NO") << endl;
		return 0;
	}
	//cerr << "### " << root << endl;
	dfs(root, -1);
	ll checker = 0, mx = -1;
	for (int i : graph[root])
		checker += dp[i], mx = max(mx, dp[i]);
	if ((checker & 1) || mx > checker / 2)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << (dp[root] ? "NO" : "YES") << endl;
}


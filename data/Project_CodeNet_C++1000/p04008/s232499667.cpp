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

int n, k, a[maxn], mark[maxn], dp[maxn], ans;
vector<int> graph[maxn];

void dfs(int u)
{
	if (graph[u].empty())
		dp[u] = 1;
	for (int i : graph[u])
		if (!mark[i])
		{
			dfs(i);
			dp[u] = max(dp[u], ((dp[i] + 1) % k == 0 ? k : (dp[i] + 1) % k));
		}
	//cerr << "DFS AT " << u << ':' << dp[u] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	if (a[0] != 0)
		a[0] = 0, ans++;
	//cerr << '#' << ans << endl;
	for (int i = 0; i < n; i++)
		graph[a[i]].pb(i);
	for (int i : graph[0])
		mark[i] = 1;
	mark[0] = 1;
	for (int i = 0; i < n; i++)
		if (mark[i])
			dfs(i);

	/*for (int i = 0; i < n; i++)
		cerr << '_' << mark[i];
	cerr << endl;
	for (int i = 0; i < n; i++)
		cerr << '_' << dp[i];
	cerr << endl;*/

	for (int i = 0; i < n; i++)
		if (!mark[i] && dp[i] == k)
			ans++;
	cout << ans << endl;
}


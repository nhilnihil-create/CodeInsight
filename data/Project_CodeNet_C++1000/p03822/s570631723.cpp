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

int n, a[maxn], deg[maxn], dp[maxn];
vector<int> adj[maxn];
set<pair<int, int> > st;

bool cmp(int a, int b)
{
	return (dp[a] < dp[b]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	a[0] = -1;
	for (int i = 1; i < n; i++)
	{
		cin >> a[i];
		deg[--a[i]]++;
		adj[a[i]].pb(i);
	}
	for (int i = 0; i < n; i++)
		st.insert(mp(deg[i], i));

	while (!st.empty())
	{
		int now = st.begin()->ss;
		st.erase(st.begin());

		sort(all(adj[now]), cmp);
		for (int i = adj[now].size() - 1; i >= 0; i--)
			dp[now] = max(dp[now], dp[adj[now][i]] + ((int)adj[now].size() - i));

		if (a[now] != -1)
		{
			st.erase(mp(deg[a[now]], a[now]));
			st.insert(mp(--deg[a[now]], a[now]));
		}
	}

	cout << dp[0] << endl;
}


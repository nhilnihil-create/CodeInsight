#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
template<class T, class T2> inline void chkmax(T &x, const T2 &y) { if(x < y) x = y; }
template<class T, class T2> inline void chkmin(T &x, const T2 &y) { if(x > y) x = y; }
const int MAXN = (1 << 20);

int n;
vector<int> adj[MAXN];

void read()
{
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int dfs(int u, int pr = -1)
{
	int ans = 0;
	for(int v: adj[u])
		if(v != pr)
			ans ^= dfs(v, u);

	return ans + 1;
}

void solve()
{
	int answer = dfs(1) - 1;
	if(answer == 0) cout << "Bob" << endl;
	else cout << "Alice" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}


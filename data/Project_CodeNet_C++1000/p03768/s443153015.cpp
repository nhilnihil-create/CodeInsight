/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
const int MOD = 1000000007;
const int MOD1 = 998244353;
const int maxn = 100010;
const int lim = (int)1e9;
vector<int> v[maxn];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, m = 0, q = 0, x = 0, y = 0;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y; --x; --y;
		v[x].pb(y); v[y].pb(x);
	}
	cin >> q;
	vector<int> a(q);
	vector<int> d(q);
	vector<int> c(q);
	for (int i = 0; i < q; ++i)
	{
		cin >> a[i] >> d[i] >> c[i]; --a[i];
	}
	vector<int> vis(n, -1);
	vector<int> colour(n);
	for (int i = q - 1; i >= 0; --i)
	{
		queue<int> q;
		auto insert = [&](int node, int dist)
		{
			if (vis[node] < dist)
			{
				vis[node] = dist;
				if (!colour[node])
					colour[node] = c[i];
				q.push(node);
			}
		};
		insert(a[i], d[i]);
		while (!q.empty())
		{
			int fr = q.front(); q.pop();
			if (vis[fr])
			{
				for (auto j : v[fr])
					insert(j, vis[fr] - 1);
			}
		}
	}
	for (auto &i : colour)
		cout << i << "\n";
}
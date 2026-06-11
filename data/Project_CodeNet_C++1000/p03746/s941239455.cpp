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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, m = 0, x = 0, y = 0;
	cin >> n >> m;
	vector<int> v[n + 1];
	deque<int> dq;
	vector<bool> vis(n + 1, false);
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dq.pb(1); vis[1] = true;
	while (true)
	{
		bool flag = false;
		int f = dq.front();
		for (auto i : v[f])
			if (!vis[i])
			{
				dq.push_front(i); vis[i] = true; flag = true; break;
			}
		int b = dq.back();
		for (auto i : v[b])
			if (!vis[i])
			{
				dq.pb(i); vis[i] = true; flag = true; break;
			}
		if (!flag)
			break;
	}
	cout << (int)dq.size() << endl;
	for (auto i : dq)
		cout << i << " ";
}
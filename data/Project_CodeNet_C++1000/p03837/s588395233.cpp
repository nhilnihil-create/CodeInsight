#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll dis[1001];
bool vis[1001];
vector<pair<pair<ll, ll>, ll>>v[1001];
set<ll>st;
void dijkstra(ll k)
{
	multiset<pair<ll, pair<ll, ll> > > s;
	s.insert({0, {k, 0}});
	for (ll i = 0; i <= 1000; i++)
	{
		vis[i] = 0;
		dis[i] = INT_MAX;
	}
	dis[k] = 0;
	while (!s.empty())
	{
		pair<ll, pair<ll, ll>>p = *s.begin();
		s.erase(s.begin());
		ll wei = p.first;
		ll node = p.second.first;
		ll edge = p.second.second;

		if (vis[node])
			continue;
		vis[node] = 1;
		st.insert(edge);
		for (ll i = 0; i < v[node].size(); i++)
		{
			if (dis[node] + v[node][i].first.second < dis[v[node][i].first.first])
			{
				dis[v[node][i].first.first] = dis[node] + v[node][i].first.second;
				s.insert({dis[v[node][i].first.first], { v[node][i].first.first, v[node][i].second}});
			}
		}
	}
}
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt" , "r" , stdin);
// 	freopen("output.txt" , "w" , stdout);
// #endif

	ll  m;
	cin >> n >> m;
	for (ll i = 1; i <= m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({{b, c}, i});
		v[b].push_back({{a, c}, i});
	}
	for (ll i = 1; i <= n; i++)
	{
		dijkstra(i);
	}
	cout << m + 1 - st.size() << endl;
	// while (!st.empty())
	// {
	// 	cout << *st.begin() << " ";
	// 	st.erase(st.begin());
	// }



}

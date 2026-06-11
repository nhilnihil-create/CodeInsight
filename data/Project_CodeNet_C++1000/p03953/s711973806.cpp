#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 1e5 + 20;

int p[maxn] , x[maxn] , b[maxn];

bool visited[maxn];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> x[i] , p[i] = i;

	int m;
	ll k;
	cin >> m >> k;

	for(int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		t--;

		swap(p[t] , p[t - 1]);
	}

	for(int i = 0; i + 1 < n; i++)
		if(!visited[i])
		{
			vector<int> cycle;
			while(!visited[i])
			{
				visited[i] = 1;
				cycle.pb(i);
				i = p[i];
			}

			int sz = cycle.size();

			int tmp = k % sz;

			for(int j = 0; j < sz; j++)
				p[cycle[j]] = cycle[(j + tmp) % sz];
		}

	cout << x[0] << endl;
	b[0] = x[0];
	for(int i = 0; i + 1 < n; i++)
	{
		int ind = p[i];
		b[i + 1] = b[i] + (x[ind + 1] - x[ind]);
		cout << b[i + 1] << endl;
	}
}









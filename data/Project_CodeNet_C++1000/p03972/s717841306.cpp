#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
int p[N], q[N];
vector <pair <int, int> > edge;
int h, w;
signed main()
{
	int ans = 0;
	cin >> h >> w;
	for(int i = 1; i <= h; i++)
	{
		cin >> p[i];
		edge.push_back({p[i], 0});
	}
	for(int i = 1; i <= w; i++)
	{
		cin >> q[i];
		edge.push_back({q[i], 1});
	}
	h++, w++;
	sort(edge.begin(), edge.end());
	for(auto e : edge)
	{
		// cout << e.fi << ' '; 
		if(e.se == 0)
		{
			ans += (w * e.fi);
			h--;
		}
		else
		{
			ans += (h * e.fi);
			w--;
		}
		// if(h == 0 || w == 0)
			// return cout << ans, 0;
	}
	cout << ans;
}
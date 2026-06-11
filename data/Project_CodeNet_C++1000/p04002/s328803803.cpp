#include <bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mod 1000000007
// #define mod 998244353
using namespace std;

set<pi> colored;
int h, w;

bool valid(int x, int y)
{
	if (x < 2 || y < 2 || x >= h || y >= w)
	{
		return 0;
	}
	return 1;
}

int count(int x, int y)
{
	int ans = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (colored.find({x + i, y + j}) != colored.end())
			{
				ans++;
			}
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		colored.insert({a, b});
	}
	set<pi> center[10];
	for (pi p : colored)
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				int x = p.first + i, y = p.second + j;
				if (valid(x, y))
				{
					center[count(x, y)].insert({x, y});
				}
			}
		}
	}
	ll ans = (h - 2);
	ans *= (w - 2);
	for (int i = 1; i <= 9; i++)
	{
		ans -= center[i].size();
	}
	cout << ans << endl;
	for (int i = 1; i <= 9; i++)
	{
		cout << center[i].size() << endl;
	}
	return 0;
}
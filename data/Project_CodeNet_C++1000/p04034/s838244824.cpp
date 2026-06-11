#include <bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mod 1000000007
// #define mod 998244353
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<bool> flag(n);
	vector<int> count(n);
	for (int i = 0; i < n; i++)
	{
		count[i] = 1;
	}
	flag[0] = 1;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if (flag[x])
		{
			if (count[x] == 1)
			{
				flag[x] = 0;
				count[x]--;
				flag[y] = 1;
				count[y]++;
			}
			else
			{
				count[x]--;
				flag[y] = 1;
				count[y]++;
			}
		}
		else
		{
			count[x]--;
			count[y]++;
		}
	}
	int ans = 0;
	for (int x : flag)
	{
		ans += x;
	}
	cout << ans << endl;
	return 0;
}
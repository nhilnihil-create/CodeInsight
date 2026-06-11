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
	int power[21];
	power[0] = 1;
	for (int i = 1; i <= 20; i++)
	{
		power[i] = 2 * power[i - 1];
	}
	int n;
	cin >> n;
	int x[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
	}
	int l;
	cin >> l;
	int reach[n + 1][21];
	for (int j = 0; j <= 20; j++)
	{
		reach[n][j] = n;
	}
	for (int i = n - 1; i >= 1; i--)
	{
		int pos = lower_bound(x + 1, x + n + 1, x[i] + l + 1) - x;
		reach[i][0] = pos - 1;
		for (int j = 1; j <= 20; j++)
		{
			reach[i][j] = reach[reach[i][j - 1]][j - 1];
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		int ans = 0, cur_pos = a;
		while (cur_pos != b)
		{
			int next_pos;
			for (int j = 20; j >= 0; j--)
			{
				if (j == 0 || reach[cur_pos][j] < b)
				{
					ans += power[j];
					next_pos = min(b, reach[cur_pos][j]);
					break;
				}
			}
			cur_pos = next_pos;
		}
		cout << ans << endl;
	}
	return 0;
}
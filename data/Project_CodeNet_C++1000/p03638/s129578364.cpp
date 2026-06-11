#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9+7, A = 1e3+5;

int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m, x;
	cin >> n >> m >> x;
	int a[x], ptr = 0;
	for (int i = 0; i < x; i++)
		cin >> a[i];
	int ans[n][m];
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < m; j++)
			{
				ans[i][j] = ptr + 1;
				a[ptr]--;
				if (a[ptr] == 0) ptr++;
			}
		}
		else
		{
			for (int j = m - 1; j >= 0; j--)
			{
				ans[i][j] = ptr + 1;
				a[ptr]--;
				if (a[ptr] == 0) ptr++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
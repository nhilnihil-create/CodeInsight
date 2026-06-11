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
	int n, t;
	cin >> n >> t;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int count = 0, diff = 0, maxi = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i] >= maxi)
		{
			maxi = a[i];
			continue;
		}
		if (diff < maxi - a[i])
		{
			diff = maxi - a[i];
			count = 1;
		}
		else if (diff == maxi - a[i])
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
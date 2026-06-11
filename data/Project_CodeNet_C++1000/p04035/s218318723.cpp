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
	ll n, l;
	cin >> n >> l;
	ll a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int start;
	for (start = 1; start < n; start++)
	{
		if (a[start] + a[start - 1] >= l)
		{
			break;
		}
	}
	if (start == n)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	for (int i = n - 1; i > start; i--)
	{
		cout << i << endl;
	}
	for (int i = 1; i <= start; i++)
	{
		cout << i << endl;
	}
	return 0;
}
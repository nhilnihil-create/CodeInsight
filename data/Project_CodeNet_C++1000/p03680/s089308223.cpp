//Practice
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5;
const ll INF = 1e9 + 5;
const ll mxN = 1000000007;
const double E = 1e-9;

//------------------------------------------------------------------------------
int n;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ini = 1;
	if (a[1] == 1)
	{
		cout << -1;
		return 0;
	}
	if (a[1] == 2)
	{
		cout << 1;
		return 0;
	}
	ll ans = 0;
	while (ans <= n)
	{
		++ans;
		if (a[ini] == 2)
		{
			cout << ans;
			return 0;
		}
		ini = a[ini];
	}
	cout << -1;
	return 0;
}
//29-08-2020 11:45:44
//------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long int ll;
#define mod 1000000007

bool check(vector<bool> v, ll n)
{
	for (; n > 0; n /= 10)
		if (v[n % 10] )
			return false;

	return true;
}

void solve()
{
	ll n, k;
	cin >> n >> k;

	vector<bool> v(10);
	for (ll i = 0; i < k; i++)
	{
		ll index;
		cin >> index;
		v[index] = true;
	}

	while (!check(v, n))
		n++;

	cout << n;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("1input.txt", "r", stdin);
	freopen("1output.txt", "w", stdout);
#endif

	int t = 1;
	// cin >> t;

	while (t--)
	{
		solve();
		cout << "\n";
	}

	return 0;
}
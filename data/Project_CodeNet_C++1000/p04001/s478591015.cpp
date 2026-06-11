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
	string s;
	cin >> s;
	int n = s.length();
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		ll power = 1;
		for (int j = 1; j <= n - i; j++)
		{
			ll temp = (1 << max(0, n - i - j - 1));
			temp *= (1 << i);
			temp *= (s[i] - '0');
			temp *= power;
			ans += temp;
			// cout << temp << endl;
			power *= 10;
		}
		// cout << endl;
	}
	cout << ans << endl;
	return 0;
}
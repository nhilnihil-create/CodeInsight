#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	string s; cin >> s;
	ll sum = 0;
	int n = s.size() - 1;
	for (int bit = 0; bit < 1 << n; bit++)
	{
		ll sub = s[n] - 48, base = 10;
		for (int mask = 0; mask < n; mask++)
		{
			if (bit & 1 << mask)
				base = 1;
			sub += (s[n - mask - 1] - 48) * base;
			base *= 10;
		}
		sum += sub;
	}
	cout << sum << endl;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	string s;
	cin >> s;
	ll n = s.size() - 1, ans = 0;
	for (int mask = 0; mask < (1 << n); ++mask)
	{
		ll sum = s[n] - '0', base = 1;
		for (int i = n - 1; i >= 0; --i)
		{
			if (mask & (1 << i))
				base = 1;
			else 
				base *= 10;
			sum += (s[i] - '0') * base;
		}
		ans += sum;
	}
	cout << ans << endl;
}

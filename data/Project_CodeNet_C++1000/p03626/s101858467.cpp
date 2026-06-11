#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)
using namespace std;

const int mod = 1000000007;
signed main(void)
{
	int n;
	long long ans;
	string s1, s2, t;

	cin >> n >> s1 >> s2;
	rep(i, n)
	{
		if (s1[i] == s2[i])
			t += 'X'; 
		else
		{
			t += 'Y';
			i++;
		}
	}
	ans = 0;
	rep(i, t.size())
	{
		if (i == 0)
		{
			if (t[i] == 'X')
				ans = 1;
			else
				ans = 2;
		}
		else
		{
			if (t[i] == 'X')
			{
				if (t[i - 1] == 'X')
					ans *= 2;
				else if (t[i - 1] == 'Y')
					ans *= 1;
			}
			else if (t[i] == 'Y')
			{
				if (t[i - 1] == 'X')
					ans *= 2;
				else if (t[i - 1] == 'Y')
					ans *= 3;
			}
		}
		ans %= mod;
	}
	ans *= 3; 
	cout << ans % mod << endl;
	return 0;
}

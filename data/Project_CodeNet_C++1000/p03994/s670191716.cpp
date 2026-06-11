#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int k, n;
	string s;

	cin >> s >> k;
	n = s.size();
	rep(i, n)
	{
		if (s[i] == 'a') continue;
		if (26 - (s[i] - 'a') <= k)
		{
			k -= 26 - (s[i] - 'a');
			s[i] = 'a';
		}
	}
	if (k > 0)
	{
		k %= 26;
		s[n - 1] += k;
		if (s[n - 1] > 'z') 
			s[n - 1] = s[n - 1] % ('z' + 1) + 'a';
	}
	cout << s << endl;
	return 0;
}

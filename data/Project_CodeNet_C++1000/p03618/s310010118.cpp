#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s;
	map<char, long long> mp;
	long long ans;

	cin >> s;
	rep(i, s.size())
	{
		mp[s[i]]++; 
	}
	ans = 1;
	for(auto p : mp)
	{
		for(auto q : mp)
		{
			if (p.first >= q.first)
				continue;
			ans += p.second * q.second; 
		}
	}
	cout << ans << endl;
	return 0;
}
